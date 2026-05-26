class Solution {
public:

    string encode(vector<string>& strs) {
        string sol;

        for (const auto& s : strs){
            int a = s.length();

            sol += to_string(a) + "#" + s;
        }

        return sol;
    }

    vector<string> decode(string s) {
        vector<string> sol;

        for (int i = 0; i < s.length(); i++){
            string tempLength = "";
            for (int j = i; j < s.length(); j++){
                if (s[j] == '#'){
                    i = j+1;
                    break;
                }else{
                    tempLength += s[j];
                }
            }
            int length = stoi(tempLength);

            string temp = "";
            for (int j = 0; j < length; j++){
                temp+=s[i+j];
            }
            sol.push_back(temp);
            i+=length - 1;
        }
        return sol;
    }
};
