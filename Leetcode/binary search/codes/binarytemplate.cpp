#include<iostream>
using namespace std;

int rodcut(int*a, int N, int K)
{
    int left = 0;
    int right = 0;
    for(int i = 0; i<N; i++)
    {
        right=a[i]>right?a[i]:right;
    }
    while(left<right)
    {
        int mid;
        mid = left+(right-left)/2;
        int k = 0;
        for(int i = 0; i<N; i++)
        {
           k += a[i]/mid; 
        }

//this bounce is not decided by mid choosing
        if(k < K)
        {
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    return left-1;
}

int main()
{
    int a[]={10,24,15};
    cout<<rodcut(a,3,7);

    return 0;
}