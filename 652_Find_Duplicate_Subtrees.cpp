class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        if(root == NULL)
            return result;
        
        unordered_map<string, vector<TreeNode*>> hash_table;
        
        tree_hash(root, hash_table);
        
        for(auto it = hash_table.begin(); it != hash_table.end(); it++)
        {
            if((it->second).size() > 1)
                result.push_back((it->second)[0]);
        }
        return result;
        
        
    }
private:
    string tree_hash(TreeNode* root, unordered_map<string, vector<TreeNode*>> &hash_table)
    {
        if(root == NULL)
            return "";
        string s = '(' + tree_hash(root->left, hash_table) + to_string(root->val) + tree_hash(root->right, hash_table) + ')';
        hash_table[s].push_back(root);
        return s;
    }
};
/*考察哈希表，将以某个节点为根的子树哈希成为字符串，利用字符串哈希记录相应的指针*/
