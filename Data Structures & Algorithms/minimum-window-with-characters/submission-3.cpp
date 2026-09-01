class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> check, mp;
        int n = s.length(), need = 0, have = 0, l = 0, min = INT_MAX;
        for (char c : t){
            check[c]++;
        }
        need = check.size();
        int idx = l;
        for (int r = 0; r < n; r++){
            char c = s[r];
            mp[c]++;
            if (check.count(c) && check[c] == mp[c]){
                have++;
            }
            while (have == need){
                if (r - l + 1 < min){
                    min = r - l + 1;
                    idx = l;
                }
                mp[s[l]]--;
                if (check.count(s[l]) && mp[s[l]] < check[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if (min != INT_MAX){
            return s.substr(idx, min);
        }
        return "";
    }
};
