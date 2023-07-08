#include <bits/stdc++.h>
using namespace std;

int maze2(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    if(i>0 && j>0 && maze[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    

    if(dp[i][j]!=-1) return dp[i][j];

    int up= maze2(i-1, j,maze,dp);
    int left = maze2(i,j-1,maze,dp);

    return dp[i][j]= up+left;
}

int maze1(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return maze2(n-1, m-1, maze, dp);
}

int main()
{

    vector<vector<int>> maze{{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    int n = maze.size();
    int m = maze[0].size();
    cout << maze1(n, m, maze);
}