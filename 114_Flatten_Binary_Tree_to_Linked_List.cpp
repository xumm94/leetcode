    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        auto p = root;
        while(p)
        {
                if(p->left)
            {
                TreeNode* node = p->left;
                while(node->right)
                    node = node->right;
                node->right = p->right;
                p->right = p->left;
                p->left = NULL;
            }
           
           p = p->right;
        }
        return;
        
    }
