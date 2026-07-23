class Solution {
public:
    int kadanes_max(vector<int>& nums){
        int best=nums[0];
        int res_max=nums[0];
        for(int i=1;i<nums.size();i++){
            best=max(best+nums[i],nums[i]);
            res_max=max(res_max,best);
        }
        return res_max;
    }
    int kadanes_min(vector<int>& nums){
        int best=nums[0];
        int res_min=nums[0];
        for(int i=1;i<nums.size();i++){
            best=min(best+nums[i],nums[i]);
            res_min=min(res_min,best);
        }
        return res_min;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        int normal=kadanes_max(nums);
        if(normal<0) return normal;
        int rem=total_sum-kadanes_min(nums);
        return max(normal,rem);
    }
};