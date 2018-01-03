class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        stack<int> tree;
        for(int i = 0; i < len; i++)
        {
            if(isdigit(preorder[i]))
            {
                while(i < len && isdigit(preorder[i]))
                    i++;
                i--;
                tree.push(preorder[i]);
            }
            else if(preorder[i] == '#')
            {
                tree.push('#');
                while(tree.top() == '#' && tree.size() >  2)
                {
                    tree.pop();
                    if(tree.top() == '#')
                    {
                        tree.pop();
                        if(tree.empty())
                            return 0;
                        if(tree.top() == '#')
                            return 0;
                        tree.pop();
                        tree.push('#');
                    }
                    else
                    {
                        tree.push('#');
                        break;
                    }
                }
            }
            
        }
        
        return tree.top() == '#' && tree.size() == 1;
    }
};
