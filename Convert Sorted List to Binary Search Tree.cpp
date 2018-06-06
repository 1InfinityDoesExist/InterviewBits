/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct TreeNode *sortedToBST(vector<int> &A, int start, int end)
 {
     if(start > end)
     {
         return NULL;
     }
     int mid = (start + end)/2;
     struct TreeNode *root = new TreeNode(A[mid]);
     root->left = sortedToBST(A, start, mid-1);
     root->right = sortedToBST(A, mid+1, end);
     return root;
 }
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    if(A == NULL)
    {
        return NULL;
    }
    struct ListNode *ptr = A;
    while(ptr != NULL)
    {
        v.push_back(ptr->val);
        ptr = ptr->next;
    }
    struct TreeNode *root = sortedToBST(v, 0, v.size()-1);
    return root;
}
