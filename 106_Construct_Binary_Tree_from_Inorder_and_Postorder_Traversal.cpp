TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_start, int post_start, int len)
    {
        TreeNode* root = NULL;
        if(len == 0)
            return NULL;
     
        if(len == 1)
            return new TreeNode(inorder[in_start]);
        
        
        int index = 0;
        for(; index <= len; index++)
        {
            if(inorder[in_start + index] == postorder[post_start + len - 1])
                break;
        }

       
        
        root = new TreeNode(postorder[post_start + len - 1]);
        root->left = helper(inorder, postorder, in_start, post_start,index);
        root->right = helper(inorder, postorder,in_start + index + 1, post_start + index, len - index - 1);

        return root;
            
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
         TreeNode* root = helper(inorder,postorder, 0, 0, inorder.size());
        return root;
        
    }
