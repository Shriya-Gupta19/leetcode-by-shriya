class Solution {
public:
    bool correct(vector<int>&given,vector<int>&needed){
        for(int i=0;i<256;i++){
            if(given[i]<needed[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>needed(256,0);
        for(char c:t){
            needed[c]++;
        }
        vector<int>given(256,0);
        int high=0,low=0;
        int res=INT_MAX,start=0;
        for(high=0;high<s.size();high++){
            given[s[high]]++;
            while(correct(given,needed)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start=low;
                }
                given[s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX)
            return "";
        return s.substr(start,res);
    }
};