//ye vo vali knapsack nii h jisme saman tod k b le skte h, ye 0/1 knapsack h, wt[ind]<=W ai to lo vrna chor do.
//RECURRSION
//TC: O(2^n*w)
//SC: O(W)
class Solution{
    public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
       return f(n-1, W, wt, val);
    }

    int f(int ind, int W, vector<int>& wt, vector<int>& val){
        if(ind == 0) return val[ind] * (W/wt[ind]);

        int notPick = 0 + f(ind-1, W, wt, val);

        int pick = 0;
        if(wt[ind] <= W) pick = val[ind] + f(ind, W-wt[ind], wt, val);

        return max(pick, notPick);
    }
};

//MEMOIZATION
//TC: O(n*w)
//SC: O(n*W) + O(W) - dp array size + auxiliary stack space
class Solution
{
    public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) { 
        vector<vector<int>> dp(n, vector(W+1, -1));
       return f(n-1, W, wt, val, dp);
    }

    int f(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[0] == 0) return 0;
            return val[ind] * (W/wt[ind]);
        }

        if(dp[ind][W] != -1) return dp[ind][W];

        int notPick = 0 + f(ind-1, W, wt, val, dp);

        int pick = 0;
        if(wt[ind] <= W) pick = val[ind] + f(ind, W-wt[ind], wt, val, dp);

        return dp[ind][W] = max(pick, notPick);
    }
};

//TABULATION
//TC: O(n*w)
//SC: O(n*W) - dp array size
class Solution
{
    public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) { 
        vector<vector<int>> dp(n, vector(W+1, 0));

        for(int w=1; w<=W; w++){
            if(wt[0] != 0) dp[0][w] = val[0] * (w/wt[0]);
        }

        for(int ind=1; ind<n; ind++){
            for(int w=0; w<=W; w++){
                int notPick = 0 + dp[ind-1][w];

                int pick = 0;
                if(wt[ind] <= w) pick = val[ind] + dp[ind][w-wt[ind]];

                dp[ind][w] = max(pick, notPick);
            }
        }
       return dp[n-1] [W];
    }
};
