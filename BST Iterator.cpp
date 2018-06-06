/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 vector<int> ans;

BSTIterator::BSTIterator(TreeNode *root) {
    ans.clear();
    if(root == NULL)
    {
        return;
    }
    stack<struct TreeNode *> s;
    struct TreeNode *ptr = root;
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
            ans.push_back(node->val);
            ptr = node->right;
        }
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(ans.size() == 0)
    {
        return false;
    }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {

        int r = ans.front();
        ans.erase(ans.begin());
        return r;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
