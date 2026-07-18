class Solution {
public:
    int find(unordered_map<int,int>& mp){
        int maxfreq=INT_MIN;
        for(auto i:mp){
            maxfreq=max(maxfreq,i.second);
        }
        return maxfreq;
    }
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mp;
        int high=0,low=0,res=INT_MIN;
        for(int high=0;high<s.size();high++){
            mp[s[high]]++;
            int len=high-low+1;
            int max_count=find(mp);
            int diff=len-max_count;
            while(diff>k){
                mp[s[low]]--;
                low++;
                max_count=find(mp);
                len=high-low+1;
                diff=len-max_count;
            }
            if(diff<k || diff==k){
                int len=high-low+1;
                res=max(res,len);
            }
           
        }
        return res;
    }
};