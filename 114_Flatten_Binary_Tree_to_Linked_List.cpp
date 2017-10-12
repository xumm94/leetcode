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
/*不改变先序遍历的顺序呢，每个遍历到的节点都只有右子树，没有左子树*/
