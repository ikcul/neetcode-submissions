class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()){
            auto [row, col] = q.front();
            vis[row][col] = true;
            q.pop();
            for (int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m 
                && !vis[nr][nc] && heights[row][col] <= heights[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int, int>> qPac;
        queue<pair<int, int>> qAtl;

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++){
            qPac.push({0, i});
            qAtl.push({n-1, i});
        }

        for (int i = 0; i < n; i++){
            qPac.push({i, 0});
            qAtl.push({i, m - 1});
        }

        bfs(qPac, pac, heights);
        bfs(qAtl, atl, heights);
        vector<vector<int>> results;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (pac[i][j] && atl[i][j]){
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }
};
