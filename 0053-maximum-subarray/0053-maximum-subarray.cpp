class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestend=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            int y=bestend+nums[i];
            bestend=max(x,y);
            ans=max(ans,bestend);
        }
        return ans;
    }
};