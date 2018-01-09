class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"} ;
        for(int i = 0; i < val.size(); i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += s[i];
            }
        }
        
        return res;
        
    }
};


/*使用贪心算法，从大的权重向小的权重靠近，只有比大的权重小的时候，才会选择小的权重*/
