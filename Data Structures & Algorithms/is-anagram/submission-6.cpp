class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> table1;

        for (char c : s){
            table1[c]++;
        }

        std::unordered_map<char, int> table2;
        for (char c : t){
            table2[c]++;
        }

        for (int i = 0; i < 26; i++){
            char c = i + 'a';
            if (table1[c] != table2[c]){
                return false;
            }
        }
        return true;
    }
};
