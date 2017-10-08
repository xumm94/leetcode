    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return my_buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        
    }
    TreeNode* my_buildTree(vector<int>& preorder, vector<int>& inorder, int pre_s, int pre_e, int in_s, int in_e)
    {
        if(preorder.empty() || inorder.empty())
            return NULL;
        if(pre_s > pre_e || in_s > in_e)
            return NULL;
        if(pre_s == pre_e || in_s == in_e)
            return new TreeNode(preorder[pre_s]);
        int index = 0;
        for(; index <= in_e; index++)
        {
            if(inorder[in_s + index] == preorder[pre_s])
                break;
        }
        TreeNode* root = new TreeNode(inorder[in_s + index]);
        //root->left = my_buildTree(preorder, inorder, pre_s , pre_s + index - 1, in_s + 1, in_s + index);
        root->left = my_buildTree(preorder, inorder, pre_s + 1, pre_s + index, in_s, in_s + index - 1);
        //root->right = my_buildTree(preorder, inorder, pre_s + index + 1, pre_e, in_s + index + 1, in_e);
        root->right = my_buildTree(preorder, inorder, pre_s + index + 1, pre_e, in_s + index + 1, in_e);
        return root;
	}
