class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int idx = 0;
        int len = 0;
        for (int i = n-1; i>= 0; i--){
            int tempLen = 0;
            for (int j = i; j < n; j++){
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    tempLen = j - i + 1;
                    if (tempLen > len){
                        len = tempLen;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, len);
    }
};
