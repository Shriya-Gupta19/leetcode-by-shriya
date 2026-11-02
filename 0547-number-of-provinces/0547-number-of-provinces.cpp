class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                stack<int> st;
                st.push(i);
                vis[i] = 1;
                while (!st.empty()) {
                    int node = st.top();
                    st.pop();
                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !vis[j]) {
                            vis[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        }

        return count;
    }
};