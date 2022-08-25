#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//https://leetcode.com/problems/kth-largest-element-in-an-array/
// method1: using sort algo
int findKthLargest_v1(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

// method 2: min heap, priority queue
int findKthLargest_v2(vector<int>& nums, int k) {
    std::priority_queue<int, vector<int>, greater<int>> m_priority_queue;
    for (int i = 0; i < nums.size(); ++i) {
        if (m_priority_queue.size() < k) {
            m_priority_queue.push(nums[i]);
        }
        else if (m_priority_queue.top() < nums[i]) {
            m_priority_queue.pop();
            m_priority_queue.push(nums[i]);
        }
    }
    return m_priority_queue.top();
}

int main(void) {
    return 0;
}