//RECURRSION
//TC: O(2^n)
//SC: O(target)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return f(n - 1, target, nums);
    }

    int f(int ind, int target, vector<int>& nums) {
    // Base case
    if(ind == 0) {
        if(target == 0 && nums[0] == 0) return 2; // +0 and -0
        if(target == nums[0] || target == -nums[0]) return 1;
        return 0;
    }

    // Try adding +
    int plus = f(ind - 1, target - nums[ind], nums);

    // Try adding -
    int minus = f(ind - 1, target + nums[ind], nums);

    return plus + minus;
}
};
