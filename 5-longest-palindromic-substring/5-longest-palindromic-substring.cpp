/*
e.g. s = "babbac"

   b a b b a c
   ------------
b| t f t f f f 
a| f t f f t f
b| f f t t f f
b| f f f t f f
a| f f f f t f
c| f f f f f t

*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int longestStartIdx = 0;
        int longestEndIdx= 0;
        
        for (int i = dp.size()-1; i >= 0; i--){
            for (int j = dp[0].size()-1; j >= i; j--){
                if (i == j                               // Base case: One character e.g. 'a'
                    || (s[i] == s[j] && j == i+1)        // Base case: Two equal characters e.g. "bb"
                    || (s[i] == s[j] && dp[i+1][j-1])){  
                    dp[i][j] = true;
                    if ((longestEndIdx - longestStartIdx) < (j - i)){
                        longestStartIdx = i;
                        longestEndIdx = j;
                    }
                }
            }
        }
        return s.substr(longestStartIdx, (longestEndIdx - longestStartIdx + 1));
    }
};