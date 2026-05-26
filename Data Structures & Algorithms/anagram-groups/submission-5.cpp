class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> temp;

        for (string s : strs){
            
            string tempString = s;
            std::sort(tempString.begin(), tempString.end());

            temp[tempString].push_back(s);
        }

        vector<vector<string>> sol;

        for (auto it = temp.begin(); it != temp.end(); ++it){
            sol.push_back(it->second);
        }

        return sol;
    }
};
