//BEST APPROACH: SAME CODE OF LCS TABULATION, JUST RETURN THE MAXIMUM VALUE OF THE DP ARRAY
class Solution{
    public: int longestCommonSubstr (string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        int ans = 0;

        // dp[i][j] = LCS of first i chars of str1 and first j chars of str2
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));

        for (int ind1 = 1; ind1 <=n; ind1++) {
            for (int ind2 = 1; ind2 <=m; ind2++) {
                if (str1[ind1-1] == str2[ind2-1]) {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // match
                    ans = max(ans, dp[ind1][ind2]);
                } else {
                    dp[ind1][ind2] = 0; // not match
                }
            }
        }

        return ans;
    }
};










