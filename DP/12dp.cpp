#include <bits/stdc++.h>
using namespace std;

int getMax2(int i, int j, int m, vector<vector<int>> &mat,
               vector<vector<int>> &dp)
{
    if (j< 0||j>= m)
        return -1e9;
    if (i == 0)
        return mat[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = mat[i][j] + getMax2(i - 1, j, m, mat, dp);
    int leftDiagonal = mat[i][j] + getMax2(i - 1, j - 1, m,mat, dp);
    int rightDiagonal = mat[i][j] + getMax2(i - 1, j + 1, m, mat, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMax(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int max_i = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int ans = getMax2(n - 1, j, m, mat, dp);
        max_i = max(max_i, ans);
    }
    return max_i;
}

int main()
{
    vector<vector<int>> mat{{1, 2, 10, 4},
                            {100, 3, 2, 1},
                            {1, 1, 20, 2},
                            {1, 2, 2, 1}};
    cout << getMax(mat);
}