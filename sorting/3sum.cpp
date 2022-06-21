//https://leetcode.com/problems/3sum/
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    sort(nums.begin(), nums.end());
    set<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 1 && nums[i - 1] == nums[i])
            continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while(left != right) {
            if (nums[left] + nums[right] == -nums[i]) {
                result.insert({nums[i], nums[left], nums[right]});
                --right;
                while ((right > left) && (nums[right] == nums[right + 1])) {
                    --right;
                }
                continue;
            }
            if ((nums[left] + nums[right]) > -nums[i]) {
                --right;
                continue;
            }
            if ((nums[left] + nums[right]) < -nums[i]) {
                ++left;
                continue;
            }
        }
    }
    vector<vector<int>> result_final (result.begin(), result.end());
    return result_final;
}

int main() {
    vector<int> input = {-2,-2,-2,0,1,1,2, 4};
    auto output = threeSum(input);
    for (auto &set : output) {
        for (auto &c : set) {
            cout << c << " ";
        }
        cout << '\n';
    }
    return 0;
}