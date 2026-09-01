class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()){
            return "";
        }
        int l = 0, n = s.length(), min = INT_MAX;
        unordered_map<char, int> check;
        unordered_map<char, int> mp;

        for (char c : t){
            check[c]++;
        }
        int idx = 0;
        for (int r = 0; r < n; r++){
            mp[s[r]]++;
            if (min >= t.length()){
                bool contains = true;
                while (contains){
                    for (auto [key, val] : check){
                        if (check[key] > mp[key]){
                            contains = false;
                        }
                    }
                    if (contains){
                        if (r - l + 1 < min){
                            min = r - l + 1;
                            idx = l;
                        }
                        mp[s[l]]--;
                        if (mp[s[l]] == 0){
                            mp.erase(s[l]);
                        }
                        l++;
                    }
                }
            }
        }
        if (min != INT_MAX){
            return s.substr(idx, min);
        }
        return "";
    }
};
