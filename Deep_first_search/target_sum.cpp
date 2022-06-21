#include <vector>
#include <iostream>

using namespace std;

void checkTargetSum(vector<int>& nums, int next_index, int current_sum, int target, int& count) {
    if (next_index == nums.size()) {
        if (current_sum == target)
            ++count;
        return;
    }

    checkTargetSum(nums, next_index + 1, current_sum + nums[next_index], target, count);
    checkTargetSum(nums, next_index + 1, current_sum - nums[next_index], target, count);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0;
    checkTargetSum(nums, 1, nums[0], target, count);
    checkTargetSum(nums, 1, -nums[0], target, count);
    return count;
}

int main() {
    vector<int> input = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(input, target);
    return 0;
}