class Solution {
public:
    void helper(int o , int c , int n , string &t, vector<string>&ans){
        if(o==n && c==n){
            ans.push_back(t);
            return ;
        }
        //open 
        if(o <n){
            t.push_back('(');
            helper(o+1, c, n, t, ans);
            t.pop_back();
        }
        if(c<o){
            t.push_back(')');
            helper(o,c+1,n,t,ans);
            t.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string>res;
        helper(0,0,n,temp,res);
        return res;
    }
};