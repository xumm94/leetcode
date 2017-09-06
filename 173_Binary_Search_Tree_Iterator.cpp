class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        goleft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto p = mystack.top();
        mystack.pop();
        goleft(p->right);
        return p->val;
        
    }
private:
    stack<TreeNode*> mystack;
    void goleft(TreeNode* root)
    {
        
        while(root)
        {
            mystack.push(root);
            root = root->left;
        }
        return ;
    }
};


//实际考察的是二叉树的中序遍历
