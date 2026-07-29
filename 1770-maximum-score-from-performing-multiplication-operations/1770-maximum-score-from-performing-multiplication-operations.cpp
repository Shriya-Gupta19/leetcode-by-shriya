class Solution {
public:
    int m, n;
    int memo[1000][1000];
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        n = nums.size();
        m = muls.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, nums, muls);
    }
    int dp(int l, int i, vector<int>& nums, vector<int>& muls) {
        if (i == m) return 0; 
        if (memo[l][i] != -1) return memo[l][i];
        int pickLeft = dp(l+1, i+1, nums, muls) + nums[l] * muls[i]; 
        int pickRight = dp(l, i+1, nums, muls) + nums[n-(i-l)-1] * muls[i]; 
        return memo[l][i] = max(pickLeft, pickRight);
    }
};