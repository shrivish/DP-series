#include<bits/stdc++.h>
using namespace std;

    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int m)
    {
        if (i == m - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle, dp, m);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp, m);

        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(0, 0, triangle, dp, m);
    }
    int main()
    {
        vector<vector<int>> triangle{{1},
                                     {2, 3},
                                     {3, 6, 7},
                                     {8, 9, 6, 10}};

        cout << minimumTotal(triangle);
    }
