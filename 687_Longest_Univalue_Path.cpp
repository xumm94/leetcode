class Solution {
public:
  
    int helper(TreeNode* root, int& m){
        int l=root->left ? helper(root->left, m) : 0;
        int r=root->right ? helper(root->right, m) : 0;
        l=(root->left != NULL && root->left->val==root->val) ? l+1 : 0;
        r=(root->right != NULL && root->right->val==root->val) ? r+1 : 0;
        m=max(m,l+r);
        return max(l,r);
    }
    
    int longestUnivaluePath(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int max_len = 0;
        helper(root, max_len);
        return max_len;
    }
};
