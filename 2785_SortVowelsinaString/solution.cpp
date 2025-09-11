class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        vector<char> v;
        for (char c : s) {
            if (vowelSet.count(c)) {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (char &c : s) {
            if (vowelSet.count(c)) {
                c = v[idx++];
            }
        }
        
        return s;
    }
};
