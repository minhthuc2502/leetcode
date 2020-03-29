/**
 * Roman to Integer
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
*/
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i;
        string s1 = "thuc";
        map<string,int> roman = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000} };
        for(i = 0; i <s.length()-1; i++)
        {
            if(roman.at(string(1,s[i])) >= roman.at(string(1,s[i+1])))
                result += roman.at(string(1,s[i]));
            else
            {
                result += roman.at(string(1,s[i+1])) - roman.at(string(1,s[i]));
                i++;        
            }
        }
        if(i == s.length()-1)
            result += roman.at(string(1,s[i]));
    return result;
    }
};