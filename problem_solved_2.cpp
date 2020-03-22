//Given a 32-bit signed integer, reverse digits of an integer.
/**
 * 
    Example 1:

    Input: 123
    Output: 321
    Example 2:

    Input: -123
    Output: -321
    Example 3:

    Input: 120
    Output: 21
*/
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x/10!=0){
            if(result + (x%10) > INT_MAX/10   || result + (x%10) < -INT_MAX/10)
                return 0;
            result = (result + (x%10)) * 10;
            x= x/10;
        }
        result += x;
        return result;
    }
};