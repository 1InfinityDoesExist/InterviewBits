/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   struct ListNode *ptrA, *lenA = A;
   struct ListNode *ptrB, *lenB = B;
   int aNo = 1;
   int bNo = 1;
   ptrA = A;
   ptrB = B;

   int lenDifference;
   if(ptrA == NULL || ptrB == NULL )
   {
       return NULL;
   }
   else
   {
       while(lenA != NULL)
       {
           aNo++;
           lenA = lenA->next;
       }

       while(lenB != NULL)
       {
           bNo++;
           lenB = lenB->next;
       }
   /*    lenDifference = aNo - bNo;
       if(lenDifference < 0)
       {
           while(lenDifference != 0)
           {
               ptrB = ptrB->next;
               lenDifference++;
           }
           while(ptrB != NULL)
               {
                   cout << ptrB->val << " -> ";
                   ptrB = ptrB->next;
               }
       }

       else if(lenDifference > 0)
       {
           while(lenDifference != 0)
           {
               ptrA = ptrA->next;
               lenDifference--;
           }
           while(ptrA != NULL)
               {
                   cout << ptrA->val << " -> ";
                   ptrA = ptrA->next;
               }
       }

     */

       }

   }

