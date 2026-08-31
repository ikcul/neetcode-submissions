class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int r, int c){
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            vis[row][col] = true;
            board[row][col] = '#';
            for (int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m
                && !vis[nr][nc] && board[nr][nc] == 'O'){
                    q.push({nr, nc});
                    board[nr][nc] = '#';
                    vis[nr][nc] = true;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++){
            if (!vis[i][0] && board[i][0] == 'O'){
                bfs(board, vis, i, 0);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O'){
                bfs(board, vis, i, m-1);
            }
        }

        for (int i = 0; i < m; i++){
            if (!vis[0][i] && board[0][i] == 'O'){
                bfs(board, vis, 0, i);
            }
            if (!vis[n-1][i] && board[n-1][i] == 'O'){
                bfs(board, vis, n-1, i);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
