class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), l = 0, length = 0, max = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++){
            mp[s[r]]++;
            max = std::max(max, mp[s[r]]);
            if (r - l + 1 - max <= k){
                length = std::max(length, r-l + 1);
            }else{
                mp[s[l]]--;
                l++;
            }
        }
        return length;
    }
};
