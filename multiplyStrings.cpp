// https://leetcode.com/problems/multiply-strings/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int stringToInt(string num) {
    int result = 0;
    for (auto d : num) {
        result = result * 10 + (d - '0');
    }
    return result;
}

string multiply(string num1, string num2) {
    int dig1 = stringToInt(num1);
    int dig2 = stringToInt(num2);
    
    string result_str;
    int complement = 0;
    for (int i = num2.size() - 1; i >= 0; --i) {
        int curr_num2 = (num2[i] - '0') * (num1[num1.size() - 1] - '0') + complement;
        for (int j = i + 1; j < num2.size(); ++j) {
            int idx = num1.size() - 1 - (j - i);
            if (0 <= idx)
                curr_num2 += (num2[j] - '0') * (num1[idx] - '0');
        }
        result_str = char(curr_num2 % 10 + '0') + result_str;
        complement = curr_num2 / 10;
    }
    int length2 = num2.size();
    for (int i = 0; i <= num1.size() - 2; ++i) {
        int curr_num = (num2[0] - '0') * (num1[num1.size() - 2 - i] - '0') + complement;
        for (int j = 1; j < num2.size(); ++j) {
            int idx = num1.size() - 2 - i - j;
            if (0 <= idx) {
                curr_num += (num2[j] - '0') * (num1[idx] - '0');
            }
        }
        result_str = char(curr_num % 10 + '0') + result_str;
        complement = curr_num / 10;
    }
    if (complement)
        result_str = char(complement + '0') + result_str;

    return result_str;
}

int main() {
    cout << multiply("123456789", "987654321");
    return 0;
}