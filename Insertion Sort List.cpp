/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void swap(int *a, int *b)
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    for(struct ListNode *current = A; current->next != NULL; current = current->next)
    {
        for(struct ListNode *selection = current->next; selection != NULL; selection = selection->next)
        {
            if(current->val > selection->val)
            {
                swap(&current->val, &selection->val);
            }
        }
    }
    return A;
}
