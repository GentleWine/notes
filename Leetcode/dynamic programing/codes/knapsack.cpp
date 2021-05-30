#include<iostream>
#include<vector>
#include<stack>
using namespace std;
using PIIB = pair<pair<int,int>,bool>;
//greedy for fractional knapsack problem
//assume weights and perval are sorted in descending order of values per weight
double solve(int W,const vector<int>weights, const vector<double>perval)
{
    int w = 0;
    int v = 0;
    int i = 0;
    for( ; i<weights.size()&&w+weights[i]<=W; i++)
    {
        w += weights[i];
        v += perval[i];
    }
    if(i !=weights.size())
    {
        v+=(W-w)*perval[i];
    }
    return v;
}
//assume weights and values are sorted in increasing order of weights
//assume weights are integers
//be careful of 0/1 startpoints
void solve(int W,const vector<int>weights, const vector<int>values, stack<int>&items, int& value)
{
    int v[6][101];
    PIIB b[6][101];
    //init
    for(int i = 0; i <= W; i++)
    {
        v[0][i]=0;
    }
    for(int i = 1; i <= weights.size(); i++)
    {
        v[i][0]=0;
        for(int j = 1; j <= W; j++)
        {
            if(weights[i-1]<=j)
            {
                if(v[i-1][j]>=(v[i-1][j-weights[i-1]]+values[i-1]))
                {
                v[i][j]=v[i-1][j];
                b[i][j]={{i-1,j},false};
                }
                else
                {
                v[i][j]=v[i-1][j-weights[i-1]]+values[i-1];
                b[i][j]={{i-1,j-weights[i-1]},true};
                }
            }
            else
            {
                v[i][j] = v[i-1][j];
                b[i][j]={{i-1,j},false};
            }
        }
    }

    for(int i = weights.size(), j = W; i>0&&j>0;)
    {
        if(b[i][j].second)
        items.push(i-1);
        //so awful codes! makes correlation!!!attention!!!
        // i = b[i][j].first.first;
        // j = b[i][j].first.second;
        int tempi = i;
        int tempj = j;
        i = b[tempi][tempj].first.first;
        j = b[tempi][tempj].first.second;
    }
    value = v[weights.size()][W];
}

int main()
{
    int W = 100;
    vector<int>weights1 = {30,10,20,50,40};
    vector<int>weights2 = {50,40,30,20,10};
    vector<double>perval = {2.1, 2, 1.5, 1.2, 1};
    vector<int>values = {60, 40, 65, 30, 20};
    stack<int> items;
    int value;
    cout<<"fractional knapsack value: "<<solve(W, weights1,perval)<<endl;
    solve(W,weights2,values,items,value);
    cout<<"0-1 knapsack choices: ";
    while(!items.empty())
    {
        cout<<items.top()<<' ';
        items.pop();
    }
    cout<<endl<<"value: "<<value<<endl;
    return 0;
}