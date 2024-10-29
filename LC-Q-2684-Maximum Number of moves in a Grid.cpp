/*You are given a 0-indexed m x n matrix grid consisting of positive integers.
You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1)
such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

Example-1 
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
*/

//SOLUTION-
//Time Complexity- O(N*M)
//Space Complexity- O(N*M)

//TOP-DOWN approach (MEMOIZATION)

class Solution {
public:
    int solver(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp)
    {
       if(j==grid[0].size())
       return 0;
       
       if(dp[i][j]!= -1)
       return dp[i][j];

       int one=0,two=0,three=0;

       if(i>0 && j<grid[0].size()-1 && grid[i][j]<grid[i-1][j+1])
       {
        one=1+solver(grid,i-1,j+1,dp);
       }
       if(i>=0 && i<grid.size() && j<grid[0].size()-1 && grid[i][j]<grid[i][j+1])
       {
        two=1+solver(grid,i,j+1,dp);
       }
        if(i<grid.size()-1 && j<grid[0].size()-1 && grid[i][j]<grid[i+1][j+1])
       {
        three=1+solver(grid,i+1,j+1,dp);
       }

       return dp[i][j] = max({one,two,three});

       
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        
       vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)
        {
            maxi = max(maxi,solver(grid,i,0,dp));
        }

        return maxi;
    }
};
