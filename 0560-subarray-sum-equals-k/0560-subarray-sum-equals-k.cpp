class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,res=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int ques=sum-k;
            int freq=mp[ques];
            res+=freq;
            mp[sum]++;
        }
        return res;
    }
};