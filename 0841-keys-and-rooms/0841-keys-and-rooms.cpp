class Solution {
public:
    vector<bool>visit;
    void solve(int i,vector<vector<int>>&rooms){
        int n=rooms.size();
        if(visit[i]==true) return;
        visit[i]=true;
        for(int r : rooms[i]){
            solve(r,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visit = vector<bool>(n, false);
        solve(0,rooms);
        for(int i=0;i<n;i++){
            if(!visit[i]) return false;
        }
        return true;
    }
};