    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        if(root == NULL)

        return result;

        stack<TreeNode*> ptr;

        auto p = root;

        while(!ptr.empty() || p != NULL)

        {

            while(p !=NULL)

            {

                ptr.push(p);

                p = p->left;

            }

            if(!ptr.empty())

            {

                p = ptr.top();

                ptr.pop();

                result.push_back(p->val);

                p = p->right;

            }

        }

        return result;

        

    }
/*二叉树的中序遍历*/
