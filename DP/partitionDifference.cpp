#include <bits/stdc++.h>
using namespace std;

int minsubset(vector<int> &arr, int n)
{
  int totSum = accumulate(arr.begin(),arr.end(),0);

  vector < bool > prev(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    vector < bool > cur(totSum + 1, false);
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }


    int minvalue = INT_MAX;
    for(int i =0; i<totSum; i++){
      if(prev[0]==true){
        int diff = abs(i - (totSum-i));
        minvalue= min(minvalue,diff);
      }
    }
    return minvalue;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << "the min abs diff is : " << minsubset(arr, n);
}