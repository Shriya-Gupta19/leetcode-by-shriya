class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr=0;
        vector<bool>pre;
        for(auto b:nums){
            curr=(curr*2+b)%5;
            pre.push_back(curr==0);
        }
        return pre;
    }
};