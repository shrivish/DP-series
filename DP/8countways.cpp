#include <bits/stdc++.h>

using namespace std;

int count2(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // base condition
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int count1(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return count2(m, n, dp);
}

int main()
{

    int m = 3;
    int n = 2;

    cout << count1(m, n);
}