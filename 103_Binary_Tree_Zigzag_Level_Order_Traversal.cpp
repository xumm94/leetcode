    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)

        return result;

        bool flag = 0;

        

        queue<TreeNode*> ptr_tree;

        ptr_tree.push(root);

        while(!ptr_tree.empty())

        {

            vector<int> vi;

            for(int i = 0, n = ptr_tree.size(); i < n; i++)

            {

                auto p = ptr_tree.front();

                ptr_tree.pop();

                if(p->left != NULL)

                ptr_tree.push(p->left);

                if(p->right != NULL)

                ptr_tree.push(p->right);

                vi.push_back(p->val);

            }

           if(flag == 0)

           {

               result.push_back(vi);

           }

           else

           {

               reverse(vi.begin(),vi.end());

               result.push_back(vi);

           }

           flag = !flag; 

        }

        return result;

    }
