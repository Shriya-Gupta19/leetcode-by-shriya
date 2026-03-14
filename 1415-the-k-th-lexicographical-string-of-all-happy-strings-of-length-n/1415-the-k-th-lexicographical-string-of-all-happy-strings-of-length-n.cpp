class Solution {
public:
    string ans = "";
    
    void solve(int n, int &k, string curr) {
        if (curr.size() == n) {
            k--;
            if (k == 0) ans = curr;
            return;
        }

        for (char c : {'a','b','c'}) {
            if (!curr.empty() && curr.back() == c) continue;
            if (ans != "") return;
            solve(n, k, curr + c);
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return ans;
    }
};