// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//RECURRSION
//TC: O(2^(n*m))
//SC: O(n+m) = auxiliary stack space
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size()-1;
        int cols = obstacleGrid[0].size()-1;
        return f(rows,cols,obstacleGrid);
    }

    int f(int m, int n, vector<vector<int>>& obstacleGrid){
        if(m >= 0 && n >= 0 && obstacleGrid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        int top = f(m-1,n,obstacleGrid);
        int left = f(m,n-1,obstacleGrid);

        return left + top;
    }
};


//MEMOIZATION
//TC: O(n*m)
//SC: O(n*m) + O(n+m) = auxiliary stack space + dp array size
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n,-1));
        int rows = m-1;
        int cols = n-1;
        return f(rows,cols,obstacleGrid,dp);
    }

    int f(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(m >= 0 && n >= 0 && obstacleGrid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int top = f(m-1,n,obstacleGrid,dp);
        int left = f(m,n-1,obstacleGrid,dp);

        return dp[m][n] = left + top;
    }
};
