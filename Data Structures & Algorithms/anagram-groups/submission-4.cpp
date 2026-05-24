class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //haave a vector of sets that store each char in the individaul strings
        //then loop over each element in each string ensuring they match into that set 
        //then add to a vector that contains the anagrams for that specific set
        // vector<set<char>> temp;
        // for (string s : strs){
        //     set<char> tempSet;
        //     for (char c : s){
        //         tempSet.
        //     }
        // }

        //doesnt work if there are multiple occurences of a character

        std::map<std::vector<int>, std::vector<string>> tempSolution;
        std::vector<std::vector<int>> temp;
        for (string s : strs){
            std::vector<int> tempArray(26, 0);
            for (char c : s){
                tempArray[c - 'a']++;
            }
            tempSolution[tempArray].push_back(s);
        }

        std::vector<std::vector<string>> solution;
        for (auto it = tempSolution.begin(); it != tempSolution.end(); ++it){
            solution.push_back(it->second);
        }
        return solution;
    }
};
