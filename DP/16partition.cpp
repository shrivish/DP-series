#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int ind, int target, vector < int > & arr, vector < vector 
< int >> & dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSum(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSum(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}


int minsubset(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSum(n - 1, i, arr, dp);
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << "the min abs diff is : " << minsubset(arr, n);
}