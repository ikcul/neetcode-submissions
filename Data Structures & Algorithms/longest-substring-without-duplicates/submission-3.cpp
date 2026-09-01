class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //use left and right as a sliding window that increments left everytime that the right index encounters dupe
        int l = 0, n = s.length(), max = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++){
            if (mp.find(s[r]) != mp.end()){
                //we found a dupe we need to increment the left then and then subtract mp[s[l]]--
                while (s[l] != s[r]){
                    mp.erase(s[l]);
                    l++;
                }
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            max = std::max(max, r - l + 1);
        }
        return max;
    }
};
