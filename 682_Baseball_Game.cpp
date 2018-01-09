class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> score;
        int result = 0;
        for(int i = 0; i < ops.size(); i++)
        {
            if(isdigit(ops[i][0]) || ops[i][0] == '-')
            {
                int num = atoi(ops[i].c_str());
                result += num;
                score.push(num);
            }
            else if(ops[i] == "C")
            {
                result -= score.top();
                score.pop();
            }
            else if(ops[i] == "D")
            {
                int double_s = score.top() * 2;
                result += double_s;
                score.push(double_s);
            }
            else
            {
                int last = score.top();
                score.pop();
                int last_two = score.top();
                score.pop();
                int score_this_turn = last + last_two;
                score.push(last_two);
                score.push(last);
                score.push(score_this_turn);
                result += score_this_turn;
            }
        }
        
        return result;
    }
};


/*需要注意，在判断是否为数字的时候，不仅要判断首位是否为数字，还要判断是否为负数
另外，请记住STL中将字符串转换为数字的函数stoi。
*/
