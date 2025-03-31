/* 
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer. 
*/
 
//SOLUTION-

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>pos(n,0);
        vector<int>ans(n,0);

        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]*nums[i];
        }

        pos[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {          
            pos[i]=pos[i+1]*nums[i];
        }
        
        ans[0]=pos[1];
        ans[n-1]=pre[n-2];

        for(int i=1;i<=n-2;i++)
        {
            ans[i]=pre[i-1]*pos[i+1];
        }
         
         return ans;
    }
};
