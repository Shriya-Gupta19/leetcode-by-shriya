class Solution {
public:
    vector<bool> visit;
    int count = 0;

    void solve(int i, vector<vector<int>>& rooms) {
        if (visit[i]) return;

        visit[i] = true;
        count++;

        for (int r : rooms[i]) {
            solve(r, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visit = vector<bool>(n, false);

        solve(0, rooms);

        return count == n;
    }
};
