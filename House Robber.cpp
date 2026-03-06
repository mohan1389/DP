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
