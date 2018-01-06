class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0;
        int upper = 0;
        
        for(auto &c : s)
        {
            if(c == '(')
            {
                lower++;
                upper++;
            }
            else if(c == ')')
            {
                lower--;
                upper--;
            }
            else
            {
                lower--;
                upper++;
            }
            
            lower = max(0, lower);
            if(upper < 0)
                return 0;
        }
        
        return lower == 0;
    }
};

/*如果没有*，可以使用栈来解决这个问题。通过两个计数来决定范围：
lower 表示 * 为')'， upper 表示 * 为'('
其中，有几句需要注意：
	lower = max(0, lower)
    如果 * 过多， 可以认为*是空字符
if(upper < 0)
    表示先遇到了')'
*/
