    int maxArea(vector<int>& height) {
        if(height.empty())
            return 0;
        int front = 0;
        int back = height.size() - 1;
        int result = 0;
        int h;
        
        while(front < back)
        {
            h = height[front] - height[back];
            if(h == 0)
            {
                result = max(result, (back - front) * height[front]);
                front++;
                back--;      
            }
            else if( h > 0)
            {
                result = max(result, (back - front) * height[back]);
                back--;
            }
            else
            {
                result = max(result, (back - front) * height[front]);
                front++;
            }
        }
        return result;
        
    }
