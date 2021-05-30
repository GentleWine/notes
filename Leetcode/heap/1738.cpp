#include<iostream>
#include<vector>
using namespace std;

class Heap{
    int size;
    int *arr;
    int max;
    public:
    Heap(int max){
        size = 0;
        this->max = max;
        arr = new int[max];
    }
    int top()
    {
        return arr[0];
    }
    void minheapify(int pos)
    {
        int minpos = pos;
        if(2*(pos+1)<=size&&arr[2*(pos+1)-1]<arr[pos]) minpos = 2*(pos+1)-1;
        if(2*(pos+1)+1<=size&&arr[2*(pos+1)]<arr[pos]) minpos = 2*(pos+1);
        if(minpos != pos)
        {
            int temp = arr[minpos];
            arr[minpos] = arr[pos];
            arr[pos] = temp;
            minheapify(minpos);
        }
    }

    void instop(int num)
    {
       if(size == max)
       {
           if(num>arr[0])
           {
               arr[0]=num;
               minheapify(0);
           }
       } 
       else{
           arr[size]=num;
           for(int i = size; i>=0;)
           {
               if(arr[size/2]>arr[size])
               {
                   int temp = arr[size/2];
                   arr[size/2] = arr[size];
                   arr[size] = temp;
                   i/=2;
               }
               else 
                   break;
           }
           size++;
       }
    }
};
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int dp[1001][1001];
        Heap h(k);
        for(int i = 0; i<=matrix.size(); i++) dp[i][0]=0;
        for(int j = 1; j<=matrix.size(); j++) dp[0][j]=0;
        for(int i = 1; i<=matrix.size(); i++)
        {
            for(int j = 1; j<=matrix.size(); j++)
            {
                dp[i][j]=dp[i-1][j]^dp[i][j-1]^dp[i-1][j-1]^matrix[i-1][j-1];
                h.instop(dp[i][j]);
                cout<<dp[i][j]<<endl;
            }
        }
        return h.top();
    }

};
int main()
{
    Solution s;
    vector<vector<int>>matrix={{5,2},{1,6}};
    cout<<s.kthLargestValue(matrix,2);
    return 0;
}