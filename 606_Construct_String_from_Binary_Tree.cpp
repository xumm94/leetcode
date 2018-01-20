class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == NULL)
            return "";
        bool has_left = t->left != NULL;
        bool has_right = t->right != NULL;
        
        string result = "";
        
        if(has_left && has_right)
        {
            result = to_string(t->val) + '(' + tree2str(t->left) + ')';
            result += '(' + tree2str(t->right) + ')';
        }
        else if (has_left)
            result = to_string(t->val) + '(' + tree2str(t->left) + ')';
        else if(has_right)
            result = to_string(t->val) + "()" + '(' + tree2str(t->right) + ')';
        else
            result = to_string(t->val);
        
        return result;

    }
};
