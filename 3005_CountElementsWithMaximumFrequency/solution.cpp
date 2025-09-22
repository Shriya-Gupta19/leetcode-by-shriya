class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int sum=0,maxi=0;
        unordered_map<int,int>mpp;
        for(int i:nums){
            int freq=++mpp[i];
            if(freq>maxi){
                maxi=freq;
                sum=freq;
            }
            else if(maxi==freq){
                sum+=freq;
            }
        }
        return sum;
    }
};