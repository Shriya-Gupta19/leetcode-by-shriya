class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[mid] >= nums[low]) { // left half sorted
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1; // target in left half
                else
                    low = mid + 1; // search right
            } else { // right half sorted
                if (target <= nums[high] && target > nums[mid])
                    low = mid + 1; // target in right half
                else
                    high = mid - 1; // search left
            }
        }
        return -1;
    }
};