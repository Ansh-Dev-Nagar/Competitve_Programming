/*Q-You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins.
The last row of the staircase may be incomplete.Given the integer n, return the number of complete rows of the staircase you will build.

EXAMPLE -
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
*/

// SOLUTION-

// TC - O(logN) 
// SC - O(1) 

class Solution {
public:
      // Linear Search - TC - O(N)
   /* int arrangeCoins(int n) {
        int ans=0;
        int i=1;
        while(n>=i)
        {
          n-=i;
          ans++;
          i++;
        }
        return ans;
    } */

     // Binary Search - TC - O(logN)
     int arrangeCoins(int n) {
        int l=0,r=n,ans;
        
        while(l<=r)
        {
          long mid = l+(r-l)/2;
          long sum = mid*(mid+1)/2;
          if(sum>n)
            r=mid-1;
          else if(sum<n)
          {
            ans=mid; // for the case if the sum of mid+1 is greater then curr
            l=mid+1;
          }          
          else 
           return mid;
        }

        return ans;
    }
};
