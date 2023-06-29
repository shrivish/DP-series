#include <bits/stdc++.h>
using namespace std;

int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];

    int mSteps = INT_MAX;

    for(int i=1; i<=k; i++){
        
        if(ind-i>=0){
         int jump = solveUtil(ind-i, height, dp, k)+ abs(height[ind]- height[ind-i]);
            mSteps= min(jump, mSteps);
        }
    }

    return dp[ind]= mSteps;
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main(){
    int k;
    cout<<" enter the value of k: ";
    cin>>k;

    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    vector<int> dp(n,-1);
    cout<<solve(n,height,k);
}
