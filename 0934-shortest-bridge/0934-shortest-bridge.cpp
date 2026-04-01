class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<int> dir = {0,1,0,-1,0};

        // ----------- FIRST BFS (mark first island) -----------
        bool found = false;

        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n && !found; j++) {

                if(grid[i][j] == 1) {
                    queue<pair<int,int>> temp;
                    temp.push({i, j});
                    grid[i][j] = 2;

                    while(!temp.empty()) {
                        auto [x, y] = temp.front();
                        temp.pop();

                        q.push({x, y}); // store island cells

                        for(int d = 0; d < 4; d++) {
                            int nx = x + dir[d];
                            int ny = y + dir[d+1];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < n 
                               && grid[nx][ny] == 1) {
                                
                                temp.push({nx, ny});
                                grid[nx][ny] = 2;
                            }
                        }
                    }

                    found = true;
                }
            }
        }
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nx = x + dir[d];
                    int ny = y + dir[d+1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n) {

                        if(grid[nx][ny] == 1) 
                            return steps; // reached second island

                        if(grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};