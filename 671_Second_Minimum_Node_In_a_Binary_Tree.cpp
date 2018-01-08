int findSecondMinimumValue(TreeNode* root) {
    if(root == NULL)
        return -1;
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    queue<TreeNode*> table1;
    queue<TreeNode*> table2;
    table1.push(root);
    while(!table1.empty())
    {
        int n = table1.size();
        for(int i = 0; i < n;i++)
        {
            auto node = table1.front();
            table1.pop();

            int min_value = node->val;

            if(min_value < smallest)
            {
                second_smallest = smallest;
                smallest = min_value;
            }
            else if(min_value < second_smallest && min_value != smallest)
                second_smallest = min_value;


            if(node->left == NULL || node->right ==NULL)
                continue;
            table2.push(node->left);
            table2.push(node->right);

        }
        swap(table1, table2);
    }


    if(second_smallest != INT_MAX)
        return second_smallest;
    else
        return -1;

}
