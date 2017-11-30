class Solution {
public:
    Solution(vector<int> nums) :vec(nums){
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuff(vec);
        int n = vec.size();
        if(n == 0)
            return shuff;
        
        for(int i = 0; i < n; i++)
        {
            int pos = rand() % n;
            swap(shuff[pos], shuff[i]);
        }
        
        return shuff;
    }
    
private:
    vector<int> vec;
};

