#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getBinaryLength(int n)
    {
        int i = 0;
        while (pow(2, i) < n)
        {
            i++;
        }

        return pow(2, i) == n ? i+1 : i;
    }
    bool checkCommonSubStr(string S, int n)
    {
        int length = getBinaryLength(n);
        int index = 0;
        long long number = 0;
        //cout<<"n: "<<n<<", length: "<<length<<endl;

        while (index < length)
        {
            number += S[S.size() - 1 - index] == '0' ? 0 : pow(2, index);
            index++;
        }

        //cout<<"number: "<<number<<", index: "<<index<<endl;

        while (index < S.size())
        {
            if (number !=0 && number % n == 0) {
                break;
            }
            number /= 2;
            number += S[S.size() - 1 - index] == '0' ? 0 : pow(2, length - 1);

            //cout<<"number: "<<number<<", index: "<<index<<endl;

            index++;
        }

        if (number % n != 0)
        {
            return false;
        }

        return true;
    }
    bool queryString(string S, int N)
    {
        for (int i = 2; i <= N; i++)
        {
            if (!checkCommonSubStr(S, i))
            {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    Solution solution;
    cout<<solution.queryString("0101011001101101010001001111110111100110110001001111001111111011010010101001011111010010001011011011", 5)<<endl;
    return 0;
}