    int dfs(TreeNode* root, int sum)

    {

        if(root == NULL) return 0;

        if(root->val == sum)

        {

            if((root->left == NULL)&&(root->right == NULL))

                return 1;

            else

            return dfs(root->left,0) + dfs(root->right,0);

        }

        else

        return dfs(root->left,sum - root->val) + dfs(root->right, sum - root->val);

        

    }
