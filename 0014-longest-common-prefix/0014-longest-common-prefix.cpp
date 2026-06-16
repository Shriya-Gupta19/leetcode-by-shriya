class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string ans;
        string first=strs[0];
        string last=strs[strs.size()-1];
        int minlen=min(first.size(),last.size());
        for(int i=0;i<minlen;i++){
            if(first[i]!=last[i]) break;
            else{
                ans+=first[i];
            }
        }
        return ans;
    }
};