// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> mergedArray;
    int length1 = nums1.size();
    int length2 = nums2.size();
    int a = 0 ,b = 0;
    while(1) {
        if (a == length1 && b == length2)
            break;
        else if (a == length1) {
            mergedArray.push_back(nums2[b++]);
        }
        else if (b == length2) {
            mergedArray.push_back(nums1[a++]);
        }
        else {
            if (nums1[a] <= nums2[b]) {
                mergedArray.push_back(nums1[a++]);
            }
            else {
                mergedArray.push_back(nums2[b++]);
            }
        }
    }    
    int result = (length1 + length2) % 2 == 0 ? mergedArray[(length1 + length2) / 2] + mergedArray[(length1 + length2) / 2 - 1] :
                                                mergedArray[(length1 + length2) / 2];
    return result;
}

int main() {
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}