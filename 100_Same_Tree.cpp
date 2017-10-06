    bool isValidBST(TreeNode* root) {

        if(root == NULL)

        return 1;

        bool left_bal = isValidBST(root->left);

        bool righ_bal = isValidBST(root->right);

        

        auto p = root->left;

        bool large_than_left = 0;

        if(p == NULL)

        large_than_left = 1;

        else

        {

            while(p->right != NULL)

            p = p->right;

            

            if(p->val < root->val)

            large_than_left = 1;

            else

            large_than_left = 0;

        }

        

        p = root->right;

        bool small_than_righ = 0;

        if(p == NULL)

        small_than_righ = 1;

        else

        {

            while(p->left != NULL)

            p = p->left;

            if(p->val > root->val)

            small_than_righ = 1;

            else

            small_than_righ = 0;

        }

        bool result = left_bal && righ_bal && large_than_left && small_than_righ;

        return result;

    }
/*和第98个题目相同，利用递归解决即可*/
