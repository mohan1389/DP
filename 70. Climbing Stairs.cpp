//RECURRSION
class Solution {  // TC: O(2^n) || SC: O(n) - auxiliary stack space
public:
    int climbStairs(int n) {
        return f(n);
    }

    int f(int n){
        if(n == 1) return 1;
        if(n == 0) return 1;
        int left = f(n-2);
        int right = f(n-1);

        return left + right;
    }
};

//MEMOIZATION
#include<bits/stdc++.h>
class Solution { // TC: O(n) || SC: O(n) + O(n) - auxiliary stack space + dp array size
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }

    int f(int n, vector<int>dp){
        if(n == 1) return 1;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];
        int left = f(n-2,dp);
        int right = f(n-1,dp);

        return dp[n] = left + right;
    }
};

//TABULATION
#include<bits/stdc++.h>
class Solution {    // TC: O(n) || SC: O(n) - dp array size
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return f(n,dp);
    }

    int f(int n, vector<int>dp){
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//SPACE OPTIMIZATION
#include<bits/stdc++.h>
class Solution {  // TC: O(n) || SC: O(1)
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2  = 0;
        int curri = -1;
        
        for(int i=0; i<n; i++){
            curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    } 
};
