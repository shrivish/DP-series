#include <bits/stdc++.h>
using namespace std;

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][max(0, j - 1)], matrix[i - 1][min(n - 1, j + 1)]});
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
    int main()
    {
        vector<vector<int>> mat{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
        cout << minFallingPathSum(mat);
    }

