    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right)
        {
            int minh = min(height[left], height[right]);
            if(minh == height[left])
            {
                while(++left < right && height[left] < minh)
                    res += minh - height[left];
            }
            else
            {
                while(--right > left && height[right] < minh)
                    res += minh - height[right];
            }
        }
        
        return res;
    }

/*维持两个指针，求解左边和右边较小的
所能储存的水的高度必定是两个中较小的一个
如果左面的比较小，则一直向左移动，直到左面的高于当前最小值，在到达最小值之前，这些位置都可以存水，水的体积就是minh - height[left]
右侧同理*/
