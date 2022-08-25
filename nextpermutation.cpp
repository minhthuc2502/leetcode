// https://leetcode.com/problems/next-permutation/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int curr_index = nums.size() - 1;
    int curr_value;
    int pivot = 0;
    while (curr_index > 0) {
        --curr_index;
        if (nums[curr_index] >= nums[curr_index + 1])
            continue;
        else {
            pivot = curr_index;
            int tmp;
            ++curr_index;
            int min = nums[curr_index];
            int index_min = curr_index;
            while(curr_index < nums.size() - 1) {
                ++curr_index;
                if (nums[pivot] >= nums[curr_index]) {
                    break;
                }
                if (min >= nums[curr_index]) {
                    min = nums[curr_index];
                    index_min = curr_index;
                }
            }
            tmp = nums[pivot];
            nums[pivot] = nums[index_min];
            nums[index_min] = tmp;
            int l = pivot + 1;
            int r = nums.size() - 1;
            while (l <= r) {
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                ++l;
                --r;
            }
            return;
        }
    }
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        ++l;
        --r;
    }
}

int main() {
    vector<int> input = {2,3,1,3,3};
    nextPermutation(input);
    for (auto c : input) {
        cout << c << " ";
    }
    return 0;
}