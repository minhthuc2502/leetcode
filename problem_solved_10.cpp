/**
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        bool isstrStr = false;
        int i = 0;
        int index = 0;
        if(needle.size() == 0)
            return 0;
        if(needle.size() > haystack.size())
        {
            //cout<<"tren";
            return -1;
        }
        for(; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                // failed in test case "Time Limit"
                /*index = i;
                isstrStr = true;
                //cout<<"index: "<<index<<"\n";
                for(int j = 1; j < needle.size(); j++)
                {
                    if(haystack[++i] != needle[j])
                    {
                        //cout<<"i: "<<i<<"\n";
                        isstrStr = false;
                        i = index;
                        break;
                    }
                }
                if(isstrStr == true)
                {
                    return index;
                }*/
                if(haystack.compare(i,needle.size(), needle) == 0)
                    return i;
            }
        }
        return -1;
    }
};