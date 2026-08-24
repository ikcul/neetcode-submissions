class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (char c : s){
            if (isalnum(c)){
                temp+=tolower(c);
            }
        }

        int left = 0;
        int right = temp.length() - 1;
        while (left < right){
            if (temp[left] != temp[right]){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
};
