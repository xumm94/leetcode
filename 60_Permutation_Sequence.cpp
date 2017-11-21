    string getPermutation(int n, int k) {
        vector<int> permutation(n + 1, 1);
        for(size_t i = 1; i < n + 1; i++)
        {
            permutation[i] = permutation[i - 1] * i;
        }
        
        vector<char> digit = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        int num = n - 1;
        string res = "";
        while(num)
        {
            int t = (k - 1) / permutation[num];
            res.push_back(digit[t]);
            k = k - t * permutation[num];
            auto it = digit.begin() + t;
            digit.erase(it);
            num--;
        }
        res.push_back(digit[0]);
        return res;
    }
