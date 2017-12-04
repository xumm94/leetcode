class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        ostringstream os;
        queue<TreeNode*> q;
        TreeNode *curr;
        q.push(root);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr)
            {
                os << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                os << "# ";
            }
        }
        
        return os.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        istringstream is(data);
        queue<TreeNode*> q;
        string val = "";
        is >> val;
        TreeNode *res = new TreeNode(stoi(val)), *curr = res;
        q.push(curr);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(!(is >> val))
                break;
            if(val != "#")
            {
                auto left_node = new TreeNode(stoi(val));
                p->left = left_node;
                q.push(left_node);
            }
            if(!(is >> val))
                break;
            if(val != "#")
            {
                auto right_node = new TreeNode(stoi(val));
                p->right = right_node;
                q.push(right_node);
            }
        }
        
        return res;
        
    }
};


/*希望通过此题，掌握ostringstream以及istringstream的用法*/
