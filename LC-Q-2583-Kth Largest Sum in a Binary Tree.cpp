/* LC-Q-You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.

Example 1:
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
*/

//SOLUTION-
// Time complexity: O(N) - since traversing each node once
// Space complexity: O(N) - using queue for BFS and priority queue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        queue<TreeNode*>q;  // for doing BFS of tree
        priority_queue<long long>pq;  // for finding Kth largest element
        q.push(root);

      // BFS operation
        while(!q.empty())
        {
            long long n=q.size(),sum=0;
            TreeNode* curr=q.front();

            // adding elements of same level in sum
            while(n--)
            {
              q.pop();
              sum+=curr->val; 

              if(curr->left)
              q.push(curr->left);

              if(curr->right)
              q.push(curr->right);

              curr=q.front();
            }
            // pushing the sum of each level in priority queue
            pq.push(sum); 
        }

        // returning -1 if levels are less then K
        if(pq.size()<k)
        return -1;

       // k will represent number of pops we need to get the kth largest on top pf pq
        k-=1; 
        while(k--)
        {
            pq.pop();
        }

       // top of PQ is answer
        return pq.top(); 
    }
};
