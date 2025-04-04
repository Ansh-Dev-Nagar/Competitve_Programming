/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

*/

//solution- two pointer

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;

        while(j<n)
        {
            if(j<n && nums[j]!=0)
            {
                nums[i++]=nums[j++];
            }
            while(j<n && nums[j]==0)
            {
                j++;
            }
        }

        while(i<n)
        {
            nums[i++]=0;
        }

    }
};
