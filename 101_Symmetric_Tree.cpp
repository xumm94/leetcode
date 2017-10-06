TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) return NULL;

        if(((root->left == NULL) && (root->right == NULL))) return root;

        auto root_left = root->left;

        auto root_right = root->right;

        root->right = invertTree(root_left);

        root->left = invertTree(root_right);

        return root;

        }

bool isSameTree(TreeNode* p, TreeNode* q) {

        if((p == NULL) && (q == NULL)) return 1;

        if((p != NULL) && (q == NULL)) return 0;

        if((p == NULL) && (q != NULL)) return 0;

        

        if(HasLChild(p) != HasLChild(q)) return 0;

        if(HasRChild(p) != HasRChild(q)) return 0;

        

        if(!HasChild(p)) return p->val == q->val;

        bool left_same = isSameTree( p->left, q->left);

        bool Right_same = isSameTree( p->right, q->right);

        return left_same && Right_same && (p->val == q->val);

    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL) return 1;

        root->right = invertTree(root->right);

        return isSameTree(root->left, root->right);

    }
/*判断二叉树是否为对称的，对称不好写，考虑以下的步骤：
1.将左子树翻转
2.判断翻转后的左子树与右子树是否相同

感觉此题与98题类似
*/
