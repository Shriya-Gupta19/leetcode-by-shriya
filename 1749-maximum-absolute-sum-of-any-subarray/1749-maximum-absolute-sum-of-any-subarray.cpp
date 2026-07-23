class Solution {
public:
    int kadanes_max(vector<int>& nums){
        int best=nums[0];
        int max_res=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            int v2=nums[i];
            best=max(v1,v2);
            max_res=max(max_res,best);
        }
        return abs(max_res);
    }
    int kadanes_min(vector<int>& nums){
        int best=nums[0];
        int min_res=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            int v2=nums[i];
            best=min(v1,v2);
            min_res=min(min_res,best);
        }
        return abs(min_res);
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int A1=kadanes_max(nums);
        int A2=kadanes_min(nums);
        return max(A1,A2);
    }
};