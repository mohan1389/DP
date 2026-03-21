//RECURRSIVE
//TC: O(2^n)
//SC: O(amount) <-- isse thodi jada hogi complexity
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n-1, coins, amount);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int f(int ind, vector<int>& coins, int amount){
        if(amount == 0) return 0; // no more coins required
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }

        int notPick = 0 + f(ind-1, coins, amount);

        int pick = 1e9;
        if(coins[ind] <= amount){
            pick = 1 + f(ind, coins, amount-coins[ind]);
        }

        return min(pick, notPick);
    }
};


//MEMOIZATION
//TC: O(n * amount)
//SC: O(n * amount) + O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }

    int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0; // no more coins required
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = 0 + f(ind-1, coins, amount, dp);

        int pick = 1e9;
        if(coins[ind] <= amount){
            pick = 1 + f(ind, coins, amount-coins[ind], dp);
        }

        return dp[ind][amount] = min(pick, notPick);
    }
};


//TABULATION 
//TC: O(n * amount)
//SC: O(n * amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        //base cases
        for(int ind=0; ind<n; ind++){
            dp[ind][0] = 0;
        }

        for(int amt=1; amt<=amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = amt/coins[0];
            else dp[0][amt] = 1e9;
        }

        //main logic
        for(int ind=1; ind<n; ind++){
            for(int amt=1; amt<=amount; amt++){

                int notPick = 0 + dp[ind-1][amt];

                int pick = 1e9;
                if(coins[ind] <= amt){
                    pick = 1 + dp[ind][amt-coins[ind]];
                }

                dp[ind][amt] = min(pick, notPick);

            }
        }

        int ans = dp[n-1][amount];
        return ans >= 1e9 ? -1: ans;
    }
};
