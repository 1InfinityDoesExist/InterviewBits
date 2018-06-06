/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> res;
    if(A == NULL)
    {
        return 1;
    }
    stack<struct TreeNode *> s;
    struct TreeNode *ptr = A;
    while(!s.empty() || ptr)
    {
        if(ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            struct TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            ptr = node->right;
        }
    }

    int start (0);
    int end = res.size()-1;
    while(start < end)
    {
        if(res[start] + res[end] == B)
        {
            return 1;
        }
        else if(res[start] + res[end] < B)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return 0;
}
