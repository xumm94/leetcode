    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)

        return result;

        queue<TreeNode*> ptr;

        ptr.push(root);

        while(!ptr.empty())

        {

            vector<int> level;

            for(int i = 0, n = ptr.size(); i < n; i++)

            {

                auto p = ptr.front();

                ptr.pop();

                if(p->left != NULL)

                ptr.push(p->left);

                if(p->right != NULL)

                ptr.push(p->right);

                level.push_back(p->val);

            }

            result.push_back(level);

        }

        return result;

        

    }

//借助队列实现树的层次遍历
