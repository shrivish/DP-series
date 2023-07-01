#include <bits/stdc++.h>
using namespace std;

int minSum2(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return mat[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = mat[i][j] + minSum2(i - 1, j, mat, dp);
    int left = mat[i][j] + minSum2(i, j - 1, mat, dp);

    return dp[i][j] = min(up, left);
}

int minSum1(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSum2(n - 1, m - 1, mat, dp);
}

int main()
{

    vector<vector<int>> mat{{5, 9, 6},
                            {11, 5, 2}};

    int n = mat.size();
    int m = mat[0].size();

    cout << minSum1(n, m, mat);
}