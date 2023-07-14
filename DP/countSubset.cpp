#include <bits/stdc++.h>
using namespace std;

int findWays1(vector<int> &num, int k)
{
    int n = num.size();
    vector<int>prev(k+1,0);

    prev[0]= 1;

    if(num[0]<=k) prev[num[0]]= 1;

    for(int ind=1; ind<n; ind++){
        vector<int>curr(k+1,0);
        curr[0]=1;
        for(int target=1; target<=k; target++){
            int taken= 0;
            if(num[ind]<=target){
            taken = prev[target-num[ind]];
            }

            int nottaken = prev[target];

            curr[target]=taken+nottaken;
        }
        prev=curr;
    }

    return prev[k];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets " << findWays1(arr, k);
}