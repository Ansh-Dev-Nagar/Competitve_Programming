/* Q-3217 - You are given an array of integers nums and the head of a linked list.
Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
*/

// SOLUTION-
// TC - O(N)
// SC - O(N)

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

      // making a set so its easier to find element which has to be removed 
        unordered_set<int>st;
       
       for(int i=0;i<nums.size();i++)
       {
         st.insert(nums[i]);
       }
     // if head is present in set we will keep incrementing its position
       while(st.find(head->val)!=st.end())
       {
        head=head->next;
       }
    // using pointers prev and next to connect nodes which are not in set
       ListNode* prev= head;
       ListNode* next= head->next;

       while(next!=NULL)
       {
           // if node value is present in set we will keep incrementing next
          while(next!=NULL && st.find(next->val)!=st.end())
          {
            next=next->next;
          }
          // when value in next is not present in set we will connect it with prev
          prev->next=next;
          prev=prev->next;
          if(next != NULL)
          next=next->next;
       }

       return head;

    }
};
