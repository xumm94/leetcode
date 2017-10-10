  int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int num_l = minDepth(root->left);
        int num_r = minDepth(root->right);
        if(!num_l)
            return num_r + 1;
        if(!num_r)
            return num_l + 1;
    
        return (num_l > num_r) ? num_r +1 : num_l + 1 ; 
        
    }
    
