// TABULATION
//TC: O(n*K)
//SC: O(n*K) + O(n) - auxilliary stack space + dp array size
class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K+1, -1));
        return f(n-1,K,arr, dp);
	}

    int f(int ind, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int notPick = f(ind-1, target, arr, dp);

        int pick = 0;
        if(arr[ind] <= target) pick = f(ind-1, target-arr[ind], arr, dp);

        return dp[ind][target] = notPick + pick;
    }
};
