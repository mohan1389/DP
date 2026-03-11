//RECURRSION
//TC: O(2^n)
//SC: O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        if(sum & 1) return false;

        int target = sum / 2;
        return f(n-1, target, nums);
    }

    bool f(int ind, int target, vector<int>&nums){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        bool notPick = f(ind-1, target, nums);

        bool pick = false;
        if(target >= nums[ind]) pick = f(ind-1, target-nums[ind], nums);

        return pick || notPick; 
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        if(sum & 1) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, nums, dp);
    }

    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];

        bool notPick = f(ind-1, target, arr, dp);
        bool pick = false;
        if(target >= arr[ind]) pick = f(ind-1, target-arr[ind], arr, dp);

        return dp[ind][target] = pick || notPick;
    }
};



class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        if(sum & 1) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int k = 1; k <= target; k++){
                bool notPick = dp[ind-1][k];
                bool pick = false;
                if(k >= nums[ind])
                    pick = dp[ind-1][k-nums[ind]];
                dp[ind][k] = pick || notPick;
            }
        }
        return dp[n-1][target];
    }
};
