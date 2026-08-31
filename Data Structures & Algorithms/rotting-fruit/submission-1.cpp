class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int fresh = 0;
        int min = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0){
            int level = q.size();
            for (int i = 0; i < level; i++){
                auto [row, col] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++){
                    int nr = row + dr[j];
                    int nc = col + dc[j];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m 
                    && grid[row][col] == 2 && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            min++;
        }
        if (!fresh){
            return min;
        }else{
            return -1;
        }
    }
};
