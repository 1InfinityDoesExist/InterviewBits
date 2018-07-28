/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode *partition(struct ListNode *begin, struct ListNode *end)
 {
     if(begin == end)
     {
         return begin;
     }
     struct ListNode *head = begin;
     struct ListNode *temp = NULL;
     struct ListNode *pre = head;
     int value = head->val;
     while(pre != NULL)
     {
         temp = pre->next;
         if(temp == end)
         {
             break;
         }
         if(temp && temp->val < value)
         {
             pre->next = temp->next;
             temp->next = head;
             head = temp;
         }
         else
         {
             pre = temp;
         }
     }
     return head;
 }
 struct ListNode *quickSort(struct ListNode *begin, struct ListNode *end)
 {
    if(begin == end)
    {
        return begin;
    }
    struct ListNode *head = partition(begin, end);
    struct ListNode *h1 = quickSort(head, begin);
    struct ListNode *h2 = quickSort(begin->next, end);
    begin->next = h2;
    return h1;
 }
 struct ListNode *quick(struct ListNode *head)
 {
     return quickSort(head, NULL);
 }
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    struct ListNode *head = NULL;
    for(vector<ListNode *>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        struct ListNode *temp = *iter;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            struct ListNode * ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    return quick(head);
}
