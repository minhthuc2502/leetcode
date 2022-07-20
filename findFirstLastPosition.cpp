// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int length = nums.size();

    if (!length)
        return {-1, -1};
    int below = -1;
    int i = 0, count = 0;
    while (nums[i] <= target) {
        if (nums[i] == target) {
            ++count;
            if (below < 0)
                below = i;
        }
        ++i;
        if (i >= length)
            break;
    }
    if (below == -1) {
        return {-1, -1};
    }
    return {below, below + count - 1};
}

// vector<int> searchRange(vector<int>& nums, int target) {
//     int length = nums.size();
//     if (!length)
//         return {-1, -1};
//     int l = 0;
//     int r = length - 1;
//     while (l <= r) {
//         int mid = (l + r) / 2;
//         if (nums[mid] < target) {
//             l = mid + 1;
//         }
//         else if (nums[mid] > target) {
//             r = mid - 1;
//         }
//         else {
//             l = r = mid;
//             while (nums[l] == target) {
//                 --l;
//             }
//             while (nums[r] == target) {
//                 ++r;
//             }
//             break;
//         }
//     }
//     if (nums[l + 1] == target)
//         return {l + 1 , r - 1};
//     else
//         return {-1, -1};
// }

int main() {

}