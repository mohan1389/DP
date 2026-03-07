//RECURRSION
//TC: O(2^(m*n))
//SC: O(m+n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int rows = m-1;
        int cols = n-1;
        return f(rows,cols);
    }
    
    int f(int m, int n){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        int left = f(m-1,n);
        int right = f(m,n-1);

        return left + right;
    }
};

//MEMOIZATION
//TC: O(m*n)
//SC: O(m+n) + O(m*n) - auxiliary stack space + dp array size
class Solution {
public:
    int uniquePaths(int m, int n) {
        int rows = m-1;
        int cols = n-1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(rows,cols,dp);
    }

    int f(int m, int n, vector<vector<int>>&dp){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int left = f(m-1,n,dp);
        int right = f(m,n-1,dp);

        return dp[m][n] = left + right;
    }
};


//TABULATION
//TC: O(m*n)
//SC: O(m*n) - dp array size
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                else{
                   int top = 0, left = 0;

                    if(i>0) top = top + dp[i-1][j];
                    if(j>0) left = left + dp[i][j-1];

                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//SPACE-OPTIMIZATION
//TC: O(m*n)
//SC: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0)
                    curr[j] = 1;
                else{

                    int top = 0, left = 0;

                    if(i > 0)
                        top = prev[j];

                    if(j > 0)
                        left = curr[j-1];

                    curr[j] = top + left;
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};

