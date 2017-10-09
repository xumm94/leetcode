    void runDP(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int>& cur_path) {
        if(root->left == NULL && root->right== NULL) {
            // Evaluate at leaf node
            if(root->val == sum) {
                vector<int> temp; 
                temp = cur_path; 
                temp.push_back(root->val);
                ret.push_back(temp);
            }
            
        }else {
            if(root->left) {
                cur_path.push_back(root->val);
                runDP(root->left, sum - root->val, ret, cur_path);
                cur_path.pop_back();
            }
            
            if(root->right) {
                cur_path.push_back(root->val);
                runDP(root->right, sum - root->val, ret, cur_path);
                cur_path.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur_path;
        if(root == NULL){
            return ret;
        }
        
        runDP(root, sum , ret, cur_path);
        return ret;
        
    }
