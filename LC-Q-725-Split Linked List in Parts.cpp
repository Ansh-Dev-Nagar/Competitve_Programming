/* Q-725-Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.
*/
// SOLUTION--

// My Approach
/* First case - If K > Size of LL
then we have to put individual node of LL in array and leave remaining
elements as NULL;
Second case - If K <= Size of LL
then first we will calculate if we have extra remaining, then we will
divide LL in equal parts but add remaining one by one in each part until
remaining becomes 0. */

//Time complexity: O(N+K)
//Space complexity: O(N+k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        vector<ListNode*>ans(k,NULL);
   // calculating size of LL
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        temp=head;  
   // case when K > size     
        if(k>size)
        {
          int i=0;
          while(temp)
          {
            ans[i++]=new ListNode(temp->val);
            temp=temp->next;
          }
          return ans;
        }
  // case when k <= size
        ListNode* temp2=head;
        ListNode* temp3=head;
        int remain = size%k;
        int size2= size/k;
        for(int i=0;i<k;i++)
        {
            int val=size2;
           if(remain<=0)
           {
             val=size2-1;
           }
           else
           {
            remain--;
           }
           while(val--)
             {
                temp2=temp2->next;
             }
             temp3=temp2->next;
             temp2->next=NULL;
             ans[i]=temp;
             temp=temp3;
             temp2=temp3;
        }
        return ans;
        
    }
};
