// RECURRSION
//TC: O(2 * 2^n)
//SC: O(n) - auxiliary stack space

class Solution {
public:
    int houseRobber(vector<int>& money) {
        int ind = money.size()-1;
        return max(f1(money,ind),f2(money,ind-1));
    }

    int f1(vector<int>&arr, int ind){
        if(ind == 1) return arr[1];
        if(ind < 1) return 0;

        int pick = arr[ind] + f1(arr,ind-2);
        int notPick = 0 + f1(arr,ind-1);

        return max(pick,notPick);
    }

    int f2(vector<int>&arr, int ind){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;

        int pick = arr[ind] + f2(arr,ind-2);
        int notPick = 0 + f2(arr,ind-1);

        return max(pick,notPick);
    }
};

// MEMOIZATION
//TC: O(n) + O(n)
//SC: O(n) + O(n) + O(n) - auxiliary stack space + 2 dp array size
class Solution {
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();
        int ind = n-1;
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(f1(money,ind,dp1),f2(money,ind-1,dp2));
    }

    int f1(vector<int>&arr, int ind, vector<int>&dp1){
        if(ind == 1) return arr[1];
        if(ind < 1) return 0;

        if(dp1[ind] != -1) return dp1[ind];

        int pick = arr[ind] + f1(arr,ind-2,dp1);
        int notPick = 0 + f1(arr,ind-1,dp1);

        return dp1[ind] = max(pick,notPick);
    }

    int f2(vector<int>&arr, int ind, vector<int>&dp2){
        if(ind == 0) return arr[0];
        if(ind < 0) return 0;

        if(dp2[ind] != -1) return dp2[ind];

        int pick = arr[ind] + f2(arr,ind-2,dp2);
        int notPick = 0 + f2(arr,ind-1,dp2);

        return dp2[ind] = max(pick,notPick);
    }
};
