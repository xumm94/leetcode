    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0;

        if(!(root->left != NULL || root->right != NULL)) return 1;

        int num_left = 0;

        int num_right = 0;

        if(root->left) num_left = maxDepth(root->left);

        if(root->right) num_right = maxDepth(root->right);

        if(num_left > num_right) 

        return num_left + 1;

        else

        return num_right + 1;

        

    }
