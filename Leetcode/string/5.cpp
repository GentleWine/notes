#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int pivot = 0;
        int slen = s.length();
        for(auto i = 0; i<slen; i++)
        {
            int temp = 1;
            for(int bias=1; (i-bias)&&(slen-i-bias);bias++)
            {
                if(s[i-bias]==s[i+bias]) temp++;
            }
            if(temp>len)
            {
                len = temp;
                pivot = i;
            }

        }
        return s.substr(pivot-len+1, 2*len-1);

    }
};
int main()
{
    Solution s;
    string m= "babab";
    s.longestPalindrome(m);
    return 0;
}