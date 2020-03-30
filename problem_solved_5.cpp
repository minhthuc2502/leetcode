/**
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string common = strs[0];
        int j = common.size();
        for(int i = 1; i < strs.size(); i++)
        {
            while(j)
            {
                if(strs[i].substr(0,j) != common)
                {
                    j--;
                    common.pop_back();
                }
                else 
                    break;
            }
        }
        return common;
    }
};