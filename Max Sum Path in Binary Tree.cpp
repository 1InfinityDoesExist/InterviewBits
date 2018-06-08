
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int maxFinder(struct TreeNode *root, int &res)
 {
     if(root == NULL)
     {
         return 0;
     }
     int l = maxFinder(root->left, res);
     int r = maxFinder(root->right, res);

     int a = max(max(l, r) + root->val, root->val);
     int b = max(a, l + r +root->val);
     res = max(res, b);
     return a;
 }
int Solution::maxPathSum(TreeNode* A) {
    if(A == NULL)
    {
        return 0;
    }
    int res = INT_MIN;
    maxFinder(A, res);
    return res;
}
