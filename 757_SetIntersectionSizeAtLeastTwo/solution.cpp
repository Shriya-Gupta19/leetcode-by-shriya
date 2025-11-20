class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<int> S; 
        int s1 = -1, s2 = -1; 
        for (auto &it : intervals) {
            int start = it[0], end = it[1];
            bool has_s1 = (s1 >= start && s1 <= end);
            bool has_s2 = (s2 >= start && s2 <= end);
            if (has_s1 && has_s2) {
                continue;
            }
            else if (has_s2) {
                s1 = s2;
                s2 = end;
                S.push_back(end);
            }
            else {
                s1 = end - 1;
                s2 = end;
                S.push_back(end - 1);
                S.push_back(end);
            }
        }
        return S.size();
    }
};
