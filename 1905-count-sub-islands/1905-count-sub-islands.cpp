class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        // boundary or water
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return true;
        // check current cell
        bool isValid = (grid1[i][j] == 1);
        // mark visited
        grid2[i][j] = 0;
        // explore neighbors
        bool up = dfs(grid1, grid2, i - 1, j);
        bool down = dfs(grid1, grid2, i + 1, j);
        bool left = dfs(grid1, grid2, i, j - 1);
        bool right = dfs(grid1, grid2, i, j + 1);

        return isValid && up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};