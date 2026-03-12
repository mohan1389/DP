// RECURRSION
//TC: O(2^n)
//SC: O(n) - auxilliary stack space
class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        return f(n-1,K,arr);
	}

    int f(int ind, int target, vector<int>&arr){
        if(target == 0) return 1;
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        int notPick = f(ind-1, target, arr);

        int pick = 0;
        if(arr[ind] <= target) pick = f(ind-1, target-arr[ind], arr);

        return notPick + pick;
    }
};

//MEMOIZATION
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

//TABULATION
//TC: O(n*K)
//SC: O(n*K) - dp array size
class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        // if(arr[0] == 0) dp[0][0] = 2;
        if(arr[0] <= K) dp[0][arr[0]] += 1;
        // if(arr[0] != 0 && arr[0] <= K) dp[0][arr[0]] = 1;

        for(int ind=1; ind<n; ind++){
            for(int target = 0; target<= K; target++){
                int notPick = dp[ind-1][target];
                int pick = 0;
                if(arr[ind] <= target) pick = dp[ind-1][target-arr[ind]];

                dp[ind][target] = notPick + pick;
            }
        }

        return dp[n-1][K];
	}
};
