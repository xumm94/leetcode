class Solution {
public:
    int maxPoints(vector<Point>& points) {

        if(points.size() < 2)
            return points.size();
        
        int result = 0;
        
        for(int i = 0; i < points.size(); i++)
        {
            int localmax = 0;
            map<pair<int,int>,int> line_table;
            int vertical = 0;
            int samepoint = 0;
            for(int j = i + 1; j < points.size(); j++)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {   
                    samepoint++;
                    continue;
                }
                else if (points[i].x == points[j].x)
                {
                    vertical++;

                }
                else
                {
                    int diff_x = points[i].x - points[j].x;
                    int diff_y = points[i].y - points[j].y;
                    int gcd = GCD(diff_x, diff_y);
                    diff_x /= gcd;
                    diff_y /= gcd;
                    line_table[make_pair(diff_x, diff_y)]++;
                    localmax = max(localmax,line_table[make_pair(diff_x, diff_y)]);
                }
                
                localmax = max(localmax,vertical);
                    
            }
            
            result = max(result, localmax + samepoint + 1);
        }
        
        
        return result;
    }
    
private:
    int GCD(int a, int b) {
        
        if(b==0) return a;
        else return GCD(b, a%b);
    }
    
};



/*opera二面面试题，只想到了暴力穷举，复杂度为o(n^3)
可以优化到o(n^2),固定一个点，求其他点和该点的斜率。如果斜率相同，则说明在同一条直线上。同时，需要注意几种特殊的边界条件
（1）相同的点
（2）斜率不存在的点
*/
