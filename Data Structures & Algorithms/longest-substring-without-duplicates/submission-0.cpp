class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int n = s.length();
        int l = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++){
            if (mp.find(s[r]) != mp.end()){
                l = std::max(l, mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            length = std::max(length, r - l + 1);
        }
        return length;
    }
};
