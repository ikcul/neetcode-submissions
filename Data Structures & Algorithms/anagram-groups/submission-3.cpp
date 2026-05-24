class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rese;
        vector<vector<string>> solution;

        for (size_t i = 0; i < strs.size(); i++){
            vector<int> count(26, 0);

            for (size_t j = 0; j < strs[i].size(); j++){
                count[strs[i][j] - 'a']++;
            }

            string temp = "";

            for (int j = 0; j < 26; j++){
                temp += to_string(count[j]);
                temp += ",";
            }

            rese[temp].push_back(strs[i]);
        }

        for (const auto& p : rese){
            solution.push_back(p.second);
        }

        return solution;
    }
};
