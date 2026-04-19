class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]!= ' '){
                c+=s[i];
            }
            else if(!c.empty()){
                words.push_back(c);
                c="";
            }
        }
        if(!c.empty()){
            words.push_back(c);
        }
        string res="";
        reverse(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            res+=words[i];
            if (i < words.size() - 1) {
                res += " ";
            }
        }

        return res;
    }
};