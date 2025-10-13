class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        vector<int> prevCount(26, 0);  
        bool isFirst = true;
        for (auto &w : words) {
            vector<int> count(26, 0);
            for (char c : w)
                count[c - 'a']++;
            if (isFirst || count != prevCount) {
                result.push_back(w);
                prevCount = count;
                isFirst = false;
            }
        }
        return result;
    }
};
