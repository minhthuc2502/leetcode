/**
 * Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
// This method don't respect the request about time of leetcode
/*bool allUnique(string s, int start, int stop)
{
    string tmp;
    string chc;
    tmp = s;
    if (stop + 1 < s.size()){
        tmp = tmp.erase(stop + 1, s.size() - stop - 1);
    }
    for (int i = start; i < stop; i++)
    {
        chc = s[i];
        if (tmp.find(chc, i + 1) != string::npos)
            return false;
    }
    return true;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        else {
            int max = 1;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                {
                    if(allUnique(s, i, j))
                    {
                        if (max < (j - i + 1))
                            max = j - i + 1;
                    }
                }
            return max;
        }
    }
};*/

/**
 *  This method is faster than 98.7% C++ online submisions 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        int index[128] = {0};
        for (int i = 0, j = 0; j < n; j++)
        {
            i = (index[s[j]] >= i ?  index[s[j]] : i);
            ans = (ans >= (j - i + 1) ?  ans : j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}