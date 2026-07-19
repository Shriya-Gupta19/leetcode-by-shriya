class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0,high=0;
        int res=0;
        int k;
        unordered_map<char,int>mp;
        for(int high=0;high<s.size();high++){
            mp[s[high]]++;
            k=high-low+1;
            while(mp.size()<k){
                mp[s[low]]--;
                if(mp[s[low]]==0) mp.erase(s[low]);
                low++;
                k=high-low+1;
            }
            if(mp.size()==k){
                int len=high-low+1;
                res=max(len,res);
            }
        }
        return res;
    }
};