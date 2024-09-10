/* Q-2807- Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

//SOLUTION-

//TC -O(N)
//SC -O(N)

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
    // Function to find gcd
    int gcd (int a, int b)
    {
        //RECURSIVE

        /* if(a % b == 0)
        return b;
        return gcd (b, a%b); */

        //ITERATIVE

        while (a % b != 0 )
        {
            int temp = a % b;
            a=b;
            b=temp;
        }
        return b;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* first = head;
        ListNode* second = head->next;

        if(!second)       // case if LL have only one element
        return head;

        while(second)
        {
            int mid = gcd(first->val,second->val);
            ListNode* temp = new ListNode(mid);    // making gcd node

           // Inserting gcd node in between first and second
           
            first->next=temp;
            temp->next=second;
            first=second;
            second=second->next;
        }

        return head;
    }
};
