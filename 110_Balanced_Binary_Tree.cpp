    bool isBalanced(TreeNode* root) {

        if(root == NULL) return 1;

        bool left_bal = isBalanced(root->left);

        bool right_bal = isBalanced(root->right);

        return left_bal && right_bal && (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1);

        

    }



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
