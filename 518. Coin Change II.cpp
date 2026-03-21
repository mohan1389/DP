//RECURRSION
//TC: O(2^n)
//SC: O(n) - auxiliary stack space
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return f(n-1, coins, amount);
    }

    int f(int ind, vector<int>& coins, int amount){
        if(amount == 0) return 1;
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            else return 0;
        }

        int notPick = 0 + f(ind-1, coins, amount);

        int pick = 0;
        if(coins[ind] <= amount) pick = f(ind, coins, amount-coins[ind]);

        return pick + notPick;
    }
};


//MEMOIZATION
//TC: O(n * amount)
//SC: O(n * amount) + O(n) - dp array size + auxiliary stack space
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, coins, amount, dp);
    }

    int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            else return 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = 0 + f(ind-1, coins, amount, dp);

        int pick = 0;
        if(coins[ind] <= amount) pick = f(ind, coins, amount-coins[ind], dp);

        return dp[ind][amount] = pick + notPick;
    }
};

//TABULATION
//TC: O(n * amount)
//SC: O(n * amount) - dp array size
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //Base cases
        for(int ind=0; ind<n; ind++){
            dp[ind][0] = 1;
        }
        for(int amt=1; amt<=amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = 1;
            else dp[0][amt] = 0;
        }
        //main logic
        for(int ind=1; ind<n; ind++){
            for(int amt=1; amt<=amount; amt++){
                long long notPick = dp[ind-1][amt];
                long long pick = 0;
                if(coins[ind] <= amt) pick = dp[ind][amt-coins[ind]];

                dp[ind][amt] = pick + notPick;
            }
        }
        return dp[n-1][amount];
    }
};
