/* Q-Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different
non-empty subsets with the maximum bitwise OR.An array a is a subset of an array b if a can be obtained from b by deleting
some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

Example 1:
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]

Constraints:
1 <= nums.length <= 16
1 <= nums[i] <= 105
*/

//SOLUTION-
//Simple backtracking approach since in constraint length can be at max 16 only
// TC- O(2^N) since we have two choice either to do OR operation or not do OR operation at each step
// SC -O(N)

class Solution {
public:

   // trying all possibilities
    void solver(vector<int>& nums,int ind,int curr,int &ans,int &maxi)
    {
        if(ind == nums.size())
        {
            if(curr == maxi)  // if curr OR of subset is eqaul to maximum OR
            ans++;
            return;
        }
        
        solver(nums,ind+1,curr|nums[ind],ans,maxi); // doing OR with curr index
        solver(nums,ind+1,curr,ans,maxi);     // not doing OR with curr index

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0,ans=0;
       // finding maximum OR possible which is equal to OR of whole array
        for(int i=0;i<nums.size();i++)
        {
            maxi|=nums[i];
        }
        
        solver(nums,0,0,ans,maxi);
        return ans;
    }
};

