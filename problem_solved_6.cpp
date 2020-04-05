/**Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
 * */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        if(s.length() == 0){
            return true;
        }
        else if(s.length() == 1)
            return false;
        for(int i= 0;i <s.length(); i++)
        {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stack.size() == 0)
                    return false;
                if(s[i] == ')' && stack.top() != '(')
                    return false;
                else if (s[i] == '}' && stack.top() != '{')
                    return false;
                else if (s[i] == ']' && stack.top() != '[')
                    return false;
                stack.pop();    
            }
            else
                stack.push(s[i]);
        }
        if(stack.size() == 0)
            return true;
        return false;
};
};
