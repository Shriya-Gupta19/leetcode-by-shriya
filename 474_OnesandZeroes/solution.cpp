class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string s:strs){
            int zero=count(s.begin(),s.end(),'0');
            int one=count(s.begin(),s.end(),'1');
            for(int i=m;i>=zero;--i){
                for(int j=n;j>=one;--j){
                    dp[i][j]=max(dp[i][j],1+dp[i-zero][j-one]);
                }
            }
        }
        return dp[m][n];
    }
};