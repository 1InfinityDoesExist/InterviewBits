/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode *partition(struct ListNode *start, struct ListNode *end)
 {
     if(start == end)
     {
         return start;
     }
     struct ListNode *head = start;
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
 struct ListNode *quickSort(struct ListNode *start, struct ListNode *end)
 {
     if(start == end)
     {
         return start;
     }
     struct ListNode *head = partition(start, end);
     struct ListNode *h1 = quickSort(head, start);
     struct ListNode *h2 = quickSort(start->next, end);
     start->next = h2;
     return h1;
 }
ListNode* Solution::sortList(ListNode* A)
{
    return quickSort(A, NULL);
}
