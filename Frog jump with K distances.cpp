// RECURRSION
//TC: O(k^n)
// SC: O(n) - auxiliary stack space
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return f(heights, n-1, k);
    }

    int f(vector<int>&arr, int ind, int k){

        if(ind == 0) return 0;
        int ans = INT_MAX;

        for(int i=1; i<=k; i++){
            if(ind-i >= 0){
                int energy = f(arr,ind-i,k) + abs(arr[ind] - arr[ind-i]);
                ans = min(ans,energy);
            }
        }

        return ans;
    }
};

//MEMOIZATION
//TC: O(n * k)
// SC: O(n) + O(n) - auxiliary stack space + dp array size
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n+1, -1);
        return f(heights, n-1, k,dp);
    }

    int f(vector<int>&arr, int ind, int k, vector<int>&dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MAX;

        for(int i=1; i<=k; i++){
            if(ind-i >= 0){
                int energy = f(arr,ind-i,k,dp) + abs(arr[ind] - arr[ind-i]);
                ans = min(ans,energy);
            }
        }

        return dp[ind] = ans;
    }
};


//TABULATION
//TC: O(n * k)
// SC: O(n) - dp array size
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n, -1);
        dp[0] = 0;
        return f(heights,k,dp);
    }

    int f(vector<int>&arr,int k, vector<int>&dp){
        int n = arr.size();
        for(int ind = 1; ind<n; ind++){
            int ans = INT_MAX;
            for(int i=1; i<=k; i++){
                if(ind-i >= 0){
                    int energy = dp[ind-i] + abs(arr[ind] - arr[ind-i]);
                    ans = min(ans,energy);
                }
            }
            dp[ind] = ans;
        }
        return dp[n-1];
    }
};

