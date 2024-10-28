/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

//SOLUTION
// RECURSIVE 
    // T.C - O(m*n)
    // S.C - O(m*n) due to dp array and it will also have recursive stack space

    //function to find side length of max square submatrix
  /*  int solver(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        // base condition
        if(i<0 || j<0 || matrix[i][j]==0)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        // finding minimum of previous to find the size of current
        return dp[i][j] = 1+min({solver(i-1,j,matrix,dp),solver(i,j-1,matrix,dp),
        solver(i-1,j-1,matrix,dp)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(300,vector<int>(300,-1));
        int ans =0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=solver(i,j,matrix,dp);
            }
        }
        return ans;
    } */

    // ITERATIVE 
    // T.C - O(m*n)
    // S.C - O(1)
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int ans =0;
        
        //counting the 1's in first column to ans
        for(int i=0;i<m;i++)
        if(matrix[i][0]==1)
        ans++;

        //counting the 1's in first row except first element as its already counted
        for(int j=1;j<n;j++)
        if(matrix[0][j]==1)
        ans++;

        //calculating the square submatrices for rest of the matrix
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                continue;

                //we keep accumulating the count of submatrices by adding minimum of prev
                matrix[i][j] = 1+min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});

                //adding count
                ans+=matrix[i][j];
            }
        }
        return ans;
    } 
};
