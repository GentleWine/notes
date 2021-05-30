#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        char const Roman[]={'M','D','C','L','X','V','I'};
        int const table[]={1000,500,100,50,10,5,1};
        string result = "";
        for(int i = 0; i<7&&num!=0; i++)
        {
            if(num/table[i+i%2]==4)
            {

                continue;
            }
            if(num/table[i+i%2]==9)
            {
                continue;
            }

            for(int j = num/table[i]; j>0;j--)
            {
                result.append(1,Roman[i]);
            }
            num = num%table[i];
        }
        return result;
    }
};
int main()
{
    Solution s;
    cout<<s.intToRoman(4);
    return 0;
}