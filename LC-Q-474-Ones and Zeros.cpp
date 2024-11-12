/* Q - You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

//SOLUTION
//TC - O(N*M)
//SC - O(N*M)

class Solution {
public:
    //MEMOIZATION
   /* int solver(vector<string>& strs, int m, int n, int ind,vector<vector<vector<int>>>&dp)
    {
        if(m<0 || n<0)
         return -1;
       
        if(ind==strs.size())
         return 0;

        if(dp[ind][m][n]!= -1)
        return dp[ind][m][n];

        int cnt0=0;
        for(auto it:strs[ind])
        {
            if(it=='0')
             cnt0++;       
        }
        int cnt1=strs[ind].size()-cnt0;

        int take = 1+solver(strs,m-cnt0,n-cnt1,ind+1,dp);

        int ntake = solver(strs,m,n,ind+1,dp);
        
        return dp[ind][m][n]=max(take,ntake);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solver(strs,m,n,0,dp);
    } */

    //TABULATION

    int findMaxForm(vector<string>& strs, int m, int n) {
        
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));

       for(auto it:strs)
       {
            int cnt0=0;
            for(auto itr:it)
            {
                if(itr=='0')
                cnt0++;       
            }
            int cnt1=it.size()-cnt0;

            for(int i=m;i>=cnt0;i--)
            {
                for(int j=n;j>=cnt1;j--)
                {
                    dp[i][j] = max(dp[i][j],1+dp[i-cnt0][j-cnt1]);
                }
            }

       }
       return dp[m][n];
        
    }
};
