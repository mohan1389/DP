A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.
To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists.
Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.


// RECURRSION
class Solution {  // TC: O(2^N) | SC: O(N) - auxiliary stack space
public:
    int frogJump(vector<int>& heights) {
        int ind = heights.size()-1;
        return f(heights,ind);
    }

    int f(vector<int>&arr, int ind){
        if(ind == 0) return 0;
        int left = INT_MAX;
        if(ind > 1){
            left = f(arr, ind-2) + abs(arr[ind] - arr[ind-2]);
        }
        int right = f(arr, ind-1) + abs(arr[ind] - arr[ind-1]);

        return min(left,right); 
    }
};


//MEMOIZATION
#include<bits/stdc++.h>
class Solution {   // TC: O(N) | SC: O(N) + O(N) - auxiliary stack space + dp array size
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n+1,-1);
        int ind = n-1;
        
        return f(heights,ind,dp);
    }

    int f(vector<int>&arr, int ind, vector<int>&dp){
        if(ind == 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int left = INT_MAX;
        if(ind > 1){
            left = f(arr, ind-2, dp) + abs(arr[ind] - arr[ind-2]);
        }
        int right = f(arr, ind-1, dp) + abs(arr[ind] - arr[ind-1]);

        return dp[ind] = min(left,right);
        
    }
};


//TABULATION
#include<bits/stdc++.h>
class Solution {      // TC: O(N) | SC: O(N) - dp array size
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        
        return f(heights,dp);
    }

    int f(vector<int>&arr,vector<int>&dp){
        int n = arr.size();
        for(int ind = 1; ind<n; ind++){
            int left = INT_MAX;
            if(ind > 1){
                left = dp[ind-2] + abs(arr[ind] - arr[ind-2]);
            }
            int right = dp[ind-1] + abs(arr[ind] - arr[ind-1]);

            dp[ind] = min(left,right);
        }

        return dp[n-1];
    }
};
