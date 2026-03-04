// RECURRSION
//TC: O(2^n)
//SC: O(n) - auxiliary stack space
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int ind = nums.size()-1;
        return f(nums,ind);
    }

    int f(vector<int>&arr, int ind){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;

        int pick = arr[ind] + f(arr,ind-2);
        int notPick = 0 + f(arr,ind-1);

        return max(pick,notPick);
    }
};


// MEMOIZATION
//TC: O(n)
//SC: O(n) + O(n) - auxiliary stack space + dp array size
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ind = n-1;
        return f(nums,ind,dp);
    }

    int f(vector<int>&arr, int ind, vector<int>&dp){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = arr[ind] + f(arr,ind-2,dp);
        int notPick = 0 + f(arr,ind-1,dp);

        return dp[ind] = max(pick,notPick);
    }
};


//TABULATION
//TC: O(n)
//SC: O(n)- dp array size
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        return f(nums,dp);
    }

    int f(vector<int>&arr, vector<int>&dp){
        int n = arr.size();
        for(int ind =1; ind<n; ind++){
            int pick = arr[ind];
            if(ind > 1){
                pick = pick + dp[ind - 2];
            }
            int notPick = 0 + dp[ind - 1];

            dp[ind] = max(pick,notPick);
        }
        return dp[n-1];

    }
};


//SPACE-OPTIMIZATION
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int prev1 = nums[0];
        int prev2 = 0;
        int curri = INT_MIN;

        for(int ind =1; ind<n; ind++){
            int pick = nums[ind];
            if(ind > 1){
                pick = pick + prev2;
            }
            int notPick = 0 + prev1;

            curri = max(pick,notPick);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }

};
