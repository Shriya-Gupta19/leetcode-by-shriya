#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int rows = mat.size();
        int cols = mat[0].size();
        
        // heights[j] will store the height of consecutive ones ending at the current row for column j.
        std::vector<int> heights(cols, 0);
        int total_count = 0;

        // Iterate through each row
        for (int i = 0; i < rows; ++i) {
            // Update the heights array for the current row
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            for (int j = 0; j < cols; ++j) {
                int min_height = heights[j];
                // Iterate leftwards from column j to count all possible submatrices
                // with bottom-right corner (i, j)
                for (int k = j; k >= 0; --k) {
                    min_height = std::min(min_height, heights[k]);
                    total_count += min_height;
                }
            }
        }
        
        return total_count;
    }
};