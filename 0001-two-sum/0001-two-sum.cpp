class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>res;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
        if(res.find(rem)!=res.end()){
            return {res[rem],i};
            }
            res[nums[i]]=i;
        }
        return {};
    }
};