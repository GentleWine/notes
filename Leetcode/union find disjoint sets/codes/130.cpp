//use union-find disjoint sets algorithm
#include<iostream>
#include<vector>
using namespace std;


class UFDS{
    private:
        int* father;
    public:
        UFDS(int N){
            father = new int[N];
            for(int i = 0; i<N; i++)
            {
                father[i]=i;
            }
        }
        int root(int i)
        {
            while(i != father[i])
            {
                i = father[i];
            }
            return i;
        }
        bool find(int p, int q)
        {
            return root(p) == root(q);
        }
        int Union(int p, int q)
        {
            if(!find(p, q))
            {
                father[root(q)]=root(p);
            }
            return root(p);
        }

};



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        UFDS dsets = UFDS(rows*cols+1);
        for(int i = 0; i<rows; i++)
            for(int j = 0; j<cols; j++)
                {
                    if(board[i][j] == 'O')
                    {
                        if(i==0||i==rows-1||j==0||j==cols-1)
                        {
                            dsets.Union(i*cols+j, cols*rows);
                        }
                        else
                        {
                            if(board[i-1][j] == 'O')
                                dsets.Union(i*cols+j, (i-1)*cols+j);
                            if(board[i+1][j] == 'O')
                                dsets.Union(i*cols+j, (i+1)*cols+j);
                            if(board[i][j-1] == 'O')
                                dsets.Union(i*cols+j, i*cols+j-1);
                            if(board[i][j+1] == 'O')
                                dsets.Union(i*cols+j, i*cols+j+1);
                        }
                    }

                } 
        for(int i = 0; i<rows; i++)
            for(int j = 0; j<cols; j++)
            {
                if(board[i][j] == 'O')
                {
                    if(!dsets.find(i*cols+j, cols*rows))
                    {
                        board[i][j] = 'X';
                    }
                }

            }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> maze = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(maze);
    int rows = maze.size();
    int cols = maze[0].size();
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
        cout<<maze[i][j];
        }
        cout<<'\n';
    }
    return 0;
}