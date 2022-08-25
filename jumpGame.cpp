#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// void countStep(vector<int>& nums, int count, int& min_step, int offset_index, int curr_index, bool& found, vector<int>& nums_cnt) {
//     ++count;

//     if (min_step && min_step < count)
//         return;
//     if (offset_index + curr_index >= nums.size() - 1) {
//         min_step = count;
//         found = true;
//         return;
//     }

//     if (nums_cnt[curr_index + offset_index] && count >= nums_cnt[curr_index + offset_index]) return;
//     else {
//         nums_cnt[curr_index + offset_index] = count;
//     }

//     for (int i = nums[curr_index + offset_index]; i > 0; --i) {
//         bool sub_found = false;
//         countStep(nums, count, min_step, i, curr_index + offset_index, sub_found, nums_cnt);
//         if (sub_found)
//             break;
//     }
// }

// int jump(vector<int>& nums) {
//     if (nums.size() <= 1)
//         return 0;
//     int min_step = 0;
//     vector<int> nums_cnt(nums.size());
//     for (int i = nums[0]; i > 0; --i) {
//         bool found;
//         countStep(nums, 0, min_step, i, 0, found, nums_cnt);
//         if (found)
//             break;
//     }
//     return min_step;
// }

int jump(vector<int>& nums) {
    int max_r = 0;
    int steps = 0;
    int r = 0;
    for (int i = 0; i < nums.size(); ++i) {
        max_r = max(max_r, i + nums[i]);
        if (i == r) {
            r = max_r;
            ++steps;
        }
    }
    return steps;
}

int main() {
    vector<int> input = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << jump(input);
    return 0;
}