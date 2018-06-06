/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 int sum;
 void solve(struct TreeNode *root, int cur)
 {
     cur = (((cur)%1003*10)%1003 + (root->val)%1003)%1003;
     if(root->left == NULL && root->right == NULL)
     {
         sum = ((sum%1003) + (cur%1003))%1003;
     }
     if(root->left)
     {
         solve(root->left, cur);
     }
     if(root->right)
     {
         solve(root->right, cur);
     }
 }
int Solution::sumNumbers(TreeNode* A) {

    if(A == NULL)
    {
        return 0;
    }
    if(A->left == NULL && A->right == NULL)
    {
        return A->val;
    }
    sum = 0;
    solve(A, 0);
    return sum%1003;
}
