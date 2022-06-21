#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                int sum = 0;
                for (int k = j; k <= i; ++k) {
                    sum += nums[k];
                }
                max = std::max(sum, max);
            }
        }
        return max;
    }

    int maxSubArray_v2(vector<int>& nums) {
        int* dp = new int[nums.size() + 1];
        dp[0] = nums[0];
        int max = nums[0];
        int i = 1;

        for (auto num : nums) {
            dp[i] = std::max(num, dp[i - 1] + num);
            max = std::max(max, dp[i++]);
        }
        return max;
    }
};

int main() {
    return 0;
}