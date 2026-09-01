class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, n = s.length(), freq = 0, max = 0;
        unordered_map<char, int> mp;


        for (int r = 0; r < n; r++){
            mp[s[r]]++;
            freq = std::max(freq, mp[s[r]]);
            if (r - l - freq + 1 <= k){
                max = std::max(max, r - l + 1);
            }else{
                //left needs to be changed
                mp[s[l]]--;
                l++;
            }
        }
        return max;
    }
};
