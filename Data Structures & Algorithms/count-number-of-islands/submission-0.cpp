class Solution {
public:
    void bfs(int start_row, int start_col, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({start_row, start_col});
        vis[start_row][start_col] = true;
        int n = grid.size(), m = grid[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                !vis[nr][nc] && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
