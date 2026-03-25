//RECURRSIVE
//TC: O(2^(m+n))
//SC: O(m+n) - auxiliary stack space
class Solution {
  public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        return f(n-1,m-1,str1,str2);
    }

    int f(int ind1, int ind2, string str1, string str2){
        if(ind1<0 || ind2<0) return 0;
        //match
        if(str1[ind1] == str2[ind2]) return 1 + f(ind1-1, ind2-1, str1, str2);
        //not match
        return 0 + max(f(ind1-1, ind2, str1, str2), f(ind1, ind2-1, str1, str2));
    }
};

//MEMOIZATION
//TC: O(n*m)
//SC: O(n*m) + O(m+n)- dp array size + auxiliary stack space
class Solution {
  public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1,m-1,str1,str2, dp);
    }

    int f(int ind1, int ind2, string str1, string str2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        //match
        if(str1[ind1] == str2[ind2]) return 1 + f(ind1-1, ind2-1, str1, str2, dp);
        //not match
        return dp[ind1][ind2] = 0 + max(f(ind1-1, ind2, str1, str2, dp), f(ind1, ind2-1, str1, str2, dp));
    }
};


//TABULATION
//TC: O(n*m)
//SC: O(n*m)-dp array size
class Solution {
public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = LCS of first i chars of str1 and first j chars of str2
        vector<vector<int>> dp(n , vector<int>(m, 0));

        for (int ind1 = 0; ind1 < n; ind1++) {
            for (int ind2 = 0; ind2 < m; ind2++) {
                if (str1[ind1] == str2[ind2]) {
                    dp[ind1][ind2] = 1 + (ind1>0 && ind2>0 ? dp[ind1 - 1][ind2 - 1] : 0); // match
                } else {
                    dp[ind1][ind2] = max((ind1>0 ? dp[ind1 - 1][ind2] : 0),(ind2>0 ? dp[ind1][ind2-1] : 0)); // not match
                }
            }
        }

        return dp[n-1][m-1];
    }
};






