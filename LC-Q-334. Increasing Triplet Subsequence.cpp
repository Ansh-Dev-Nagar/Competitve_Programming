/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
If no such indices exists, return false.

Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 
Constraints:
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 
Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

//SOLUTION-1- S(n) = O(N)  (not optimized)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         int n=nums.size();
         vector<int>mini(n,0);
         vector<int>maxi(n,0);
 
        if(n<3)
        return false;

         int minimum=nums[0];
         int maximum=nums[n-1];

         for(int i=0;i<n;i++)
         {
            minimum=min(minimum,nums[i]);
            mini[i]=minimum;
         }

         for(int i=n-1;i>=0;i--)
         {
            maximum=max(maximum,nums[i]);
            maxi[i]=maximum;
         }

         for(int i=1;i<n-1;i++)
         {
           if(nums[i]!=mini[i] && nums[i]!=maxi[i])
           return true;
         }

         return false;
    }
};

//SOLUTION-2- S(n) = O(1) 

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     
        int first=INT_MAX,second=INT_MAX;
        for(int n:nums){
            if(n<=first) first=n;
            else if(n<=second) second=n;
            else return true;
        }
         return false;
    }
};

