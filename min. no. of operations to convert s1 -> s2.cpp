//TABULATION
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return (long long)(n + m) - (long long)(2 * lcs(word1,word2));
    }

    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = LCS of first i chars of str1 and first j chars of str2
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));

        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=m; j++) {
                if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1]; // match
                else dp[i][j] = max(dp[i - 1][j],dp[i][j-1]); // not match
            }
        }

        return dp[n][m];
    }
};

//SPACEOPTIMIZATION
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return (long long)(n + m) - (long long)(2 * lcs(word1,word2));
    }

    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = LCS of first i chars of str1 and first j chars of str2
        vector<int>prev(m+1, 0);

        for (int i = 1; i <=n; i++) {
            vector<int> curr(m+1, 0);
            for (int j = 1; j <=m; j++) {
                if (str1[i-1] == str2[j-1]) curr[j] = 1 + prev[j - 1]; // match
                else curr[j] = max(prev[j],curr[j-1]); // not match
            }

            prev = curr;
        }

        return prev[m];
    }
};
