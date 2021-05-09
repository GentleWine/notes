#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size())return -1;

        int len = bloomDay.size();
        int min = INT_MAX;
        int max = 0;
        for(int i=0;i<len;i++)
        {
            min = min<bloomDay[i]?min:bloomDay[i];
            max = max>bloomDay[i]?max:bloomDay[i];
        }
        while(min+1<max)
        {
            int mid = (max + min)/2;
            if(canMake(bloomDay, m,k,mid))
            {
                max = mid - 1;
            }
            else
            {
                min = mid;
            }
        }
        if(canMake(bloomDay, m,k,max))
        return min;
        else
        return max;

    }
    bool canMake(vector<int>& bloomDay, int m, int k, int days)
    {
        int len = bloomDay.size();
        int bouquets = 0;
        int flowers = 0;
        for(int i = 0;i<len&&bouquets<m;i++)
        {
            if(bloomDay[i]<days)
            {
                flowers++;
                if(flowers == k)
                {
                    bouquets++;
                    flowers=0;
                }
            }
            else
            {
                flowers = 0;
            }

        }
        if(bouquets >= m)
        {
            return true;
        }
        return false;
    }


};
int main()
{
    Solution s;
    vector<int> a = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    cout<<s.minDays(a, m ,k);
    return 0;
}
