class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(128, 0);
            int distinct = 0;
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                if (freq[s[j]] == 1) {
                    distinct++;
                }

                maxFreq = max(maxFreq, freq[s[j]]);
                if ((j - i + 1) == maxFreq * distinct) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
