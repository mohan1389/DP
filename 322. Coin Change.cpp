//RECURRSIVE
//TC: O(2^n)
//SC: O(n) <-- isse thodi jada hogi complexity
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
