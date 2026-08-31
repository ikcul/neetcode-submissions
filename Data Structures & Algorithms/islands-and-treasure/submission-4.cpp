class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 2147483647){
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        } 
    }
};
