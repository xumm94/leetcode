class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)
            return 0;
        int base = minutesToTest / minutesToDie + 1;
        int ans = 1;
        int num = base;
        while(num < buckets)
        {
            num *= base;
            ans++;
        }
        
        return ans;
        
    }
};
