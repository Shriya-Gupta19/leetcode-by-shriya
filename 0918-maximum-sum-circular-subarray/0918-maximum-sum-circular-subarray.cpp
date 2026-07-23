class Solution {
public:
    int kadanes_max(vector<int>& nums){
        int best=nums[0];
        int res_max=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            int v2=nums[i];
            best=max(v1,v2);
            res_max=max(res_max,best);
        }
        return res_max;
    }
    int kadanes_min(vector<int>& nums){
        int best=nums[0];
        int res_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            int v2=nums[i];
            best=min(v1,v2);
            res_min=min(res_min,best);
        }
        return res_min;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        int a=kadanes_max(nums);
        if(a<0) return a;
        int b=kadanes_min(nums);
        int c=total_sum-b;
        return max(a,c);
    }
};