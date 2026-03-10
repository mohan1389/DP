//RECURRSION
//TC: O(2^n)
//SC: O(n)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return f(n-1, target, arr);
    }

    bool f(int ind, int target, vector<int>&arr){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        bool notPick = f(ind-1, target, arr);

        bool pick = false;
        if(target >= arr[ind]) pick = f(ind-1, target-arr[ind], arr);

        return pick || notPick;
        
    }
};

//MEMOIZATION
//TC: O(n * target)
//SC: O(n * target) + O(n) - auxiliary stack space + dp array size
class Solution{   
public:
    bool isSubsetSum(vector<int> arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }

    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool notPick = f(ind-1, target, arr, dp);
        bool pick = false;
        if(target >= arr[ind])
            pick = f(ind-1, target-arr[ind], arr, dp);

        return dp[ind][target] = pick || notPick;
    }
};

//TABULATION
//TC: O(n * target)
//SC: O(n * target)
class Solution{   
public:
    bool isSubsetSum(vector<int> arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        if(arr[0] <= target)
            dp[0][arr[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int k = 1; k <= target; k++){
                bool notPick = dp[ind-1][k];
                bool pick = false;
                if(k >= arr[ind])
                    pick = dp[ind-1][k-arr[ind]];
                dp[ind][k] = pick || notPick;
            }
        }
        return dp[n-1][target];
    }
};
