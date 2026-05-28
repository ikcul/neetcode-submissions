class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<unordered_set<char>> row(9);
       vector<unordered_set<char>> col(9);
       vector<unordered_set<char>> square(9);
       
       for (size_t i = 0; i < board.size(); i++){
        for (size_t j = 0; j < board[0].size(); j++){
            char idx = board[i][j];
            int squareId = (i/3)*3 + (j/3);
            if (idx == '.'){
                continue;
            }else if (row[i].contains(idx) || col[j].contains(idx) || square[squareId].contains(idx)){
                return false;
            }
            else{
                row[i].insert(idx);
                col[j].insert(idx);
                square[squareId].insert(idx);
            }
        }
       }
       return true;
    }
};
