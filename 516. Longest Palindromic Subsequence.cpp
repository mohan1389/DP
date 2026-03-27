//Approach: reverse the given string and find the LCS of two strings
//RECURRSIVE
//TC: O(2^(n+n))
//SC: O(n+n) - auxiliary stack space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return f(s1.size(), s2.size(), s1, s2);
    }

    int f(int i, int j, string &s1, string &s2){
        if(i==0 || j==0) return 0;
        if(s1[i-1] == s2[j-1]) return 1 + f(i-1,j-1, s1, s2);
        return max(f(i-1,j, s1, s2), f(i,j-1, s1, s2));
    }
};

//MEMOIZATION
//TC: O(n*n)
//SC: O(n*n) + O(n+n)- dp array size + auxiliary stack space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        return f(s1.size(), s2.size(), s1, s2, dp);
    }

    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;

        if(dp[i][j] != 0) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f(i-1,j-1, s1, s2, dp);
        return dp[i][j] = max(f(i-1,j, s1, s2, dp), f(i,j-1, s1, s2, dp));
    }
};

//TABULATION
//TC: O(n*n)
//SC: O(n*n)- dp array size
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};

//SPACEOPTIMIZATION
//TC: O(n*n)
//SC: O(n)- curr and prev array size
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        vector<int> prev(n+1,0);
        for(int i=1; i<=n; i++){
            vector<int> curr(n+1,0);
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};


