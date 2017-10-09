    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)

        return result;

        

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

            result.push_back(vi);

        }

        reverse(result.begin(),result.end());

        return result;

    }

/*首先进行广度优先搜索，最后倒过来即可*/
