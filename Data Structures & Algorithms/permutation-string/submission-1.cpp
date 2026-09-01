class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1mp;
        unordered_map<char, int> mp;
        int n = s2.length();
        int l = 0;
        for (char c : s1){
            s1mp[c]++;
        }

        for (int r = 0; r < n; r++){
            mp[s2[r]]++;
            if (r - l + 1 == s1.length()){
                if (s1mp == mp){
                    return true;
                }
                mp[s2[l]]--;
                if (mp[s2[l]] == 0){
                    mp.erase(s2[l]);
                }
                l++;
            }
        }

        return false;
    }
};
