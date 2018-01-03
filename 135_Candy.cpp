class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return -1;
        if(ratings.size() == 1)
            return 1;
        vector<int> l2r(ratings.size(), 0);
        vector<int> r2l(ratings.size(), 0);
        
        l2r[0] = 1;
        r2l[ratings.size() - 1] = 1;
        
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i - 1])
                l2r[i] = l2r[i - 1] + 1;
            else
                l2r[i] = 1;
        }
        
        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
                r2l[i] = r2l[i + 1] + 1;
            else
                r2l[i] = 1;
        }
        
        int res = 0;
        for(int i = 0; i < ratings.size(); i++)
            res += max(l2r[i], r2l[i]);
        
        return res;
    }
};
/*
  先从左向右，再从右向左。
  从左往右的时候，当右边的数大于左边的数时，右边的蜡烛数应当为左边的蜡烛数加一，否则右边的蜡烛数应当为1.
  从右往左的时候，当左边的数大于右边的数时，左边的蜡烛数应当为右边的蜡烛数加一，否则左边的蜡烛数应为1.
  此时，得到两个数组，l2r和r2l。对于某个固定的位置i，i处的蜡烛数应当为max(l2r[i], r2l[i])
  解释：假设r2l[i]大于l2r[i]。如果拥有l2r[i]个蜡烛，证明左边是满足条件的，现在将蜡烛数增加，那么一定还是满足左边的条件。r2l[i]是满足右边的条件的，所以右边也是满足的。
*/
