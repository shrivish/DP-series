#include <bits/stdc++.h>
using namespace std;

int maxum(int ind, vector<int>&arr, vector<int>&dp){

    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    if(dp[ind]!=-1)return dp[ind];

    int pick = arr[ind]+maxum(ind-2, arr, dp);
    int notpick = 0+maxum(ind-1, arr, dp);

    return dp[ind]= max(pick,notpick);
}

int solve(int n, vector<int>&arr){
    vector<int>dp(n,-1);
    return maxum(n-1,arr,dp);
}

int main(){
    vector<int>arr{2,1,4,9};
    int n = arr.size();
    cout<< solve(n, arr);
}

