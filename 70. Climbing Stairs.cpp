//BRUTEFORCE
class Solution {  // TC: O(2^n) || SC: O(n) - auxiliary stack space
public:
    int climbStairs(int n) {
        return f(n);
    }

    int f(int n){
        if(n == 1) return 1;
        if(n == 0) return 1;
        int left = f(n-2);
        int right = f(n-1);

        return left + right;
    }
};
