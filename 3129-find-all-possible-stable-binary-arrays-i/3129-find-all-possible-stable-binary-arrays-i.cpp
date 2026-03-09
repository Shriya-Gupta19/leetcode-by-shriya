class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(zero + 1, vector<long long>(one + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;

                    if (i > limit)
                        dp[i][j] = (dp[i][j] - dp[i-limit-1][j] + MOD) % MOD;
                }

                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;

                    if (j > limit)
                        dp[i][j] = (dp[i][j] - dp[i][j-limit-1] + MOD) % MOD;
                }
            }
        }
        return dp[zero][one];
    }
};