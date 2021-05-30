#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int P[301];
        int result = 0;

    //means 0 to 0;
        P[0] = arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            P[i]=P[i-1]^arr[i];
            if(P[i]==0) result+=i;
        }
        for(int k=2; k<arr.size(); k++)
        {
            for(int i = 1; i<k;i++)
            {
                //be careful of the priorities of notions!
                if((P[i-1]^P[k])==0)result+=k-i;
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v ={2,3,1,6,7};
    cout<<s.countTriplets(v);
}