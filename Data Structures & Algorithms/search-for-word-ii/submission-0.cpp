class Solution {
private:
    struct TrieNode{
        TrieNode* characters[26];
        bool end;

        TrieNode(){
            end = false;
            for (int i = 0; i < 26; i++){
                characters[i] = nullptr;
            }
        }
    };

    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }
    void add(string word){
        TrieNode* curr = root;
        for (char c : word){
            int idx = c-'a';
            if (!curr->characters[idx]){
                curr->characters[idx] = new TrieNode();
            }
            curr = curr->characters[idx];
        }
        curr->end = true;
    }
    // we are dfsing through the board so uhhh
    void dfs(TrieNode* root, int r, int c, vector<vector<char>>& board, vector<string>& result, string& currWord){
        TrieNode* curr = root;
        int idx = board[r][c] - 'a';
        char letter = board[r][c];

        if (!curr->characters[idx]){return;}
        curr = curr->characters[idx];
        board[r][c] = '#';
        currWord.push_back(letter);
        if (curr && curr->end){
            result.push_back(currWord);
            curr->end = false;
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#'){
                dfs(curr, nr, nc, board, result, currWord);
            }
        }
        board[r][c] = letter;
        currWord.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string s : words){
            add(s);
        }

        // we have now built the trie, now we need to iterate through the board and utilize dfs in order to see if it has a valid combination that exists in the current trie
        vector<string> result;
        string curr = "";
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                dfs(root, i, j, board, result, curr);
            }
        }
        return result;
    }
};
