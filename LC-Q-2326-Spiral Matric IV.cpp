/* Q-2326- You are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. 
If there are remaining empty spaces, fill them with -1.
Return the generated matrix.
*/

//SOLUTION
// TC - O(M*N)
// SC - O(M*N)

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode* temp=head;
         int startrow=0,startcol=0,endrow=m-1,endcol=n-1;
        while(temp)
        {
            // filling start row
           for(int i=startcol;i<=endcol && temp ;i++)
           {
             ans[startrow][i]=temp->val;
             temp=temp->next;
           }
           startrow++;
           // filling end col
           for(int i=startrow;i<=endrow && temp; i++)
           {
             ans[i][endcol]=temp->val;
             temp=temp->next;
           }
           endcol--;
           // filling end row
           for(int i=endcol;i>=startcol && temp ;i--)
           {
             ans[endrow][i]=temp->val;
             temp=temp->next;
           }
           endrow--;
           // filling start col
           for(int i=endrow;i>=startrow && temp; i--)
           {
             ans[i][startcol]=temp->val;
             temp=temp->next;
           }
           startcol++;

        }
        return ans;
    }
};
