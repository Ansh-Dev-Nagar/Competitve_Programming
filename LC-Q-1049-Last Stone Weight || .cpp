/* Q - You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.

*/

//SOLUTION -

// Time complexity: O(n * sum)
// Space complexity: O(n * sum)

class Solution {
public:
    // MEMOIZATION
  /*  
   int solver(vector<int>& stones, int ind,int sum, int &Tsum,vector<vector<int>>&dp)
    {
        if(ind==stones.size())
        {
          // returning difference of subset of two subsets 
            return abs((Tsum-sum)-sum);
        }

        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
         
         // Making possible subsets
        int Take = solver(stones,ind+1,sum+stones[ind],Tsum,dp);
        
        int nTake = solver(stones,ind+1,sum,Tsum,dp);

         return dp[ind][sum] = min(Take,nTake);
    }


    int lastStoneWeightII(vector<int>& stones) {

     int Tsum=0;
     for(auto it:stones)
     {
        Tsum+=it;
     }

     vector<vector<int>>dp(stones.size()+1,vector<int>(Tsum+1, -1));

      return solver(stones,0,0,Tsum,dp);
    } 
 */

    // TABULATION
    int lastStoneWeightII(vector<int>& stones) {

     int sum=0;
     for(auto it:stones)
     {
        sum+=it;
     }

     //initiating 2d DP which will store if we can get sum j with i number of stones
     vector<vector<bool>>dp(stones.size()+1,vector<bool>(sum/2+1, false));

     //making first column true as sum 0 is possible in every case
     for(int i=0;i<dp.size();i++)
     {
        dp[i][0]=true;
     }

     //filling the dp

     for(int i=1;i<dp.size();i++)
     {
        for(int j=1;j<dp[0].size();j++)
        {
            if(stones[i-1]<=j)
            dp[i][j]= dp[i-1][j-stones[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
     }
        int ans = INT_MAX;
     
     // we start j from mid as we need sum as close as possible to sum/2 so we can get min diff
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[stones.size()][j])
              ans= min(ans,sum-2*j);
        }
        

      return ans;

    }
   
    
};
