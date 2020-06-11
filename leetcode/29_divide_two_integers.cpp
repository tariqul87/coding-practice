#include "array.cpp"

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        int negatives = 2;
        
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        
        int result = 0;
        int HALF_INT_MIN = -1073741824;

        /*
        if a - b >= 0, check if a - (b << 1) >= 0
        so, until a is greater that the "subtract" part, continuously left shift
        which is basically multiplying by 2

        when the value is less that 0, add "multiplication" part with it,
        here 1 << number_of_times_b_was_left_shifted

        then subtract the highest value that was possible to substract from a (meaning b << number_of_times_b_was_left_shifted)

        But, problem is, if true reuslt is INT_MIN, then you can't take abs() of that value
        so, think all values are negative and calculate by that way 
        */
        while (divisor >= dividend)
        {
            int powerOfTwo = -1;
            int value = divisor;
            
            while(value >= HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
            
            result += powerOfTwo;
            dividend -= value;
        }

        return negatives == 1 ? result : -result;
    }
};

int main(void)
{
    Solution s;
    cout << s.divide(-2147483648, -3) << endl;
    return 0;
}