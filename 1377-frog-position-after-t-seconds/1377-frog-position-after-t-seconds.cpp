class Solution {
public:
    double ans = 1;
    vector<int> adj[100];
    vector<int> options;
    void dfs(int node, int par, int t, int target){
        if(node == target){
            if(options.size() > t){
                ans = 0;
            }
            if(options.size() < t && (node == 0 ? (adj[node].size() >= 1) : (adj[node].size() > 1))){
                ans = 0;
            }
            for(auto j:options) ans/=j;
            return;
        }
        int add = adj[node].size()-1;
        if(node == 0) add++;
        options.push_back(add);
        for(auto j:adj[node]){
            if(j == par) continue;
            dfs(j, node, t, target);
        }
        options.pop_back();
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for(auto &j:edges){
            j[0]--; j[1]--;
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
        dfs(0, -1, t, --target);
        return ans;
    }
};       
