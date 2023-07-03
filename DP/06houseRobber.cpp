#include <bits/stdc++.h>
using namespace std;

long long int robMain(vector<int> &arr)
{
    int n = arr.size();
    long int prev = arr[0];
    long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        // pick
        long long int pick = arr[i];
        if (i > 1)
            pick += prev2;
        // not pick
        long long int notpick = 0 + prev;
        long long int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1(begin(nums), end(nums) - 1);
    vector<int> temp2(begin(nums) + 1, end(nums));
    return max(robMain(temp1), robMain(temp2));
}

int main()
{
    vector<int> nums{2, 3, 2};
    int n = nums.size();
    int ans= rob(nums);
    cout<<"the ans is "<< ans;
}