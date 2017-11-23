class Solution {
public:
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return ;
        
        if(root->left)
            inorder(root->left);
        
        if(pre != NULL && root->val < pre->val)
        {
            if(mistake1 == NULL)
            {
                mistake1 = pre;		//此处第一次写时做错了，需要注意
                mistake2 = root;
            }
            else
                mistake2 = root;
        }
        
        pre = root;
        
        if(root->right)
            inorder(root->right);
        
        return ;
    }
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        if(mistake1 != NULL && mistake2 != NULL)
            swap(mistake1->val, mistake2->val);
        return ;
    }
private:
    TreeNode* mistake1 ;
    TreeNode* mistake2 ;
    TreeNode* pre;
};



/*考察二叉搜索树的中序遍历，由于只有两个节点错误，按照中序遍历，必定出现一次或者两次逆序。如果出现一次逆序，说明两个错误的元素挨在一起；如果出现两次逆序，则说明两个错误的元素被分隔开来，代码中注释的部分需要注意，如果是第一次出现逆序，两个元素都需要记录下来，用来应付两个错误元素挨在一起的这种情况。*/
