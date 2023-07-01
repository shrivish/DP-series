#include <bits/stdc++.h>
using namespace std;

int findWays(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notTaken = findWays(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWays(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken + taken;
}

int findWays1(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWays(n - 1, k, num, dp);
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets " << findWays1(arr, k);
}