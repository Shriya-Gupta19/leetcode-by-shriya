class Solution {
public:
    int solve(vector<int>&memo,int n){
        if (n==0) return 0;
        if(memo[n]!=-1){
            return memo[n];
        }
        int ans=INT_MAX;
        int i=1;
        while(i*i<=n){
            ans=min(ans,1+solve(memo,n-(i*i)));
            i+=1;
        }
        memo[n]=ans;
        return ans;
    }
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return solve(memo,n);
    }
};