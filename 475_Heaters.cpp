class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> result(houses.size(), INT_MAX);

        
        for(int i = 0, j = 0; i < houses.size() && j < heaters.size();)
        {
            if(houses[i] <= heaters[j])
            {
                result[i] = heaters[j] - houses[i];
                i++;
            }
            else
            {
                j++;
            }
        }
        

        for(int i = houses.size() - 1, j = heaters.size() - 1; i >=0 && j >=0;)
        {
            if(houses[i] >= heaters[j])
            {
                result[i] = min(result[i], houses[i] - heaters[j]);
                i--;
            }
            else
            {
                j--;
            }
        }
        
        int final_result = 0;
        for(int i = 0; i < result.size(); i++)
            final_result = max(result[i], final_result);
        
        
        return final_result;
    }
};


/*和之前做过的一个蜡烛的问题很相似，先从左往右找到一个半径，再从右向左找一个半径，然后找两个半径的较小值。
只想到了从左往右找，忘了从右往左找。
*/
