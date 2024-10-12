/*
You are given an array of integers nums of size 3.
Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
Note that the binary representation of any number does not contain leading zeros.

Example 1:
Input: nums = [1,2,3]
Output: 30
Explanation:
Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
*/

// SOLUTION -
// TC - O(N)
// SC - O(N)

class Solution {
public:

   // converting decimal number into binary string
    string binry ( int n)
    {
        string ans;
        while(n>0)
        {
           ans+=char(n%2 + '0');
           n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

  // converting binary string to decimal number
    int deci (string s)
    {
        int ans=0,j=0;
       for(int i=s.size()-1;i>=0;i--)
       {
         if(s[i]=='1')
          ans+= pow(2,j);
          j++;
       }
       return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        
        // since array only has three elements we will store their binary value
        string a = binry(nums[0]);
        string b = binry(nums[1]);
        string c = binry(nums[2]);

       // we will compare all possible combinations to find maximum value
        string ans = max (a+b+c ,a+c+b);
        ans = max (ans,b+a+c);
        ans = max (ans,b+c+a);
        ans = max (ans,c+a+b);
        ans = max (ans,c+b+a);
        
      // return the decimal value of maximum binary string
        return deci(ans);
    } 
};
