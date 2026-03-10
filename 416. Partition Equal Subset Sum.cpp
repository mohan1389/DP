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
