//Approach: reverse the given string and find the LCS of two strings
//RECURRSIVE
//TC: O(2^(m+n))
//SC: O(m+n) - auxiliary stack space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return f(s1.size(), s2.size(), s1, s2);
    }

    int f(int i, int j, string &s1, string &s2){
        if(i==0 || j==0) return 0;
        if(s1[i-1] == s2[j-1]) return 1 + f(i-1,j-1, s1, s2);
        return max(f(i-1,j, s1, s2), f(i,j-1, s1, s2));
    }
};





