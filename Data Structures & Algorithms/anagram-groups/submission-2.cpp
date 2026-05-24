class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        unordered_map<string, vector<string>> results;

        for (size_t i = 0; i < strs.size(); i++){
            vector<int> count(26, 0);

            for (size_t j = 0; j < strs[i].size(); j++){
                count[strs[i][j] - 'a']++;
            }

            string temp_string = "";

            for (int j = 0; j < 26; j++){
                temp_string += to_string(count[j]);
                temp_string += ",";
            }

            results[temp_string].push_back(strs[i]);
        }

        for (const auto& temp : results){
            solution.push_back(temp.second);
        }

        return solution;

    }
};
