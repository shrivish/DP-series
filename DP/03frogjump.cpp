#include <bits/stdc++.h>
using namespace std;

int frogjump(int ind, vector<int>&height, vector<int>&dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];

    int jump2= INT_MAX;
    int jump1= frogjump(ind-1,height,dp)+ abs(height[ind]-height[ind-1]);

    
    if(ind>1){
        jump2= frogjump(ind-2,height,dp)+ abs(height[ind]-height[ind-2]);
    }

    return dp[ind]= min(jump1,jump2);
}

int main(){
    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    vector<int> dp(n,-1);
    cout<<frogjump(n-1,height,dp);
}

