    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> tree;
        if(start > end)
        {
            tree.push_back(nullptr);
            return tree;
        }
        
        if(start == end)
        {
            tree.push_back(new TreeNode(start));
            return tree;
        }
        
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> left_sub = helper(start, i - 1);
            vector<TreeNode*> righ_sub = helper(i + 1, end);
            
            for(int j = 0; j < left_sub.size(); j++)
            {
                for(int k = 0; k < righ_sub.size(); k++)
                {
                    TreeNode *curr = new TreeNode(i);
                    curr->left = left_sub[j];
                    curr->right = righ_sub[k];
                    tree.push_back(curr);
                }
            }
        }
        
        return tree;
    } 



    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        {
            vector<TreeNode*> result;
            return result;
        }
        vector<TreeNode*> result = helper(1, n);
        return result;    
    }

