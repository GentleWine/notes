#include<iostream>
#include<math.h>
using namespace std;
class Solution {
private:
    int max_steps = 500;
    int max_pos = 250;
    int mod=pow(10,9) + 7;
    // an array storing the partial solutions which are the probable numbers of situations.
    int f[501][251]={0};
public:
    int numWays(int steps, int arrLen) {
        //essential!

        f[0][0] = 1;

        for(int i = 1; i<=steps; i++)
            for(int j = 0; j<=steps/2&&j<arrLen; j++)
            {
                long long n1 = 0, n2 = 0, n3 = 0;
                n2 = f[i-1][j]%mod;
                if(j+1 <=steps/2&&j+1<arrLen)
                {
                    n3 = f[i-1][j+1]%mod;
                }
                if(j-1>=0)
                {
                    n1 = f[i-1][j-1]%mod;
                }
                f[i][j] = (n1+n2+n3)%mod;

            }
        return f[steps][0];
    }
};
int main()
{
    Solution s;
    cout<<s.numWays(27,7);
    return 0;
}