#include <bits/stdc++.h>
using namespace std;

int sum1(vector<int> &dp)
{
    int sum = 0;
    for (auto i : dp)
    {
        sum = sum + i;
    }
    return sum;
}

void printAll(int ind, vector<int> &arr, vector<int> &dp, int n, int k)
{

    if (ind == n)
    {
        // print dp
        int sum = sum1(dp);
        if (sum == k)
        {
            for (auto i : dp)
            {
                cout << i << " ";
            }
        }
        return;
    }

    // pick
    dp.push_back(arr[ind]);
    printAll(ind + 1, arr, dp, n, k);
    dp.pop_back();

    // not pick
    printAll(ind + 1, arr, dp, n, k);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int k = 11;
    int n = arr.size();
    vector<int> dp;
    printAll(0, arr, dp, n, k);
}