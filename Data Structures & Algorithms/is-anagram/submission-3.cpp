class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> seens;
        unordered_map<char, int> seent;
        

        for (auto character : s){
            seens[character]++;
        }

        for (auto character : t){
            seent[character]++;
        }

        for (auto character : s){
            if (seens[character] != seent[character]){
                return false;
            }
        }
        return true;

    }
};
