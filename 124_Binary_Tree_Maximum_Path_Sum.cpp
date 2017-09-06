 int maxsum(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        int l = maxsum(root->left, res), r = maxsum(root->right, res);
        if(l < 0)
            l = 0;
        if(r < 0)
            r = 0;
        
        res = max(root->val + l + r, res);
        
        return root->val + max(l, r);
        
    }


 int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = INT_MIN;
        maxsum(root, res);
        return res;
}
