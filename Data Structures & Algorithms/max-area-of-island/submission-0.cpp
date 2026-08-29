class Solution {
public:
    int bfs(int start_row, int start_col, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({start_row, start_col});
        vis[start_row][start_col] = true;
        int count = 1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                    count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == 1){
                    max = std::max(max, bfs(i, j, vis, grid));
                }
            }
        }

        return max;

    }
};
