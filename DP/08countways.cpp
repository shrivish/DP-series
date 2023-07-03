// #include <bits/stdc++.h>
// using namespace std;

// int countways2(int i, int j, vector<vector<int>>&dp){
//     //base case
//     if(i==0 && j==0) return 1;
//     if(i<0 || j<0) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];

//     int up= countways2(i-1, j,dp);
//     int left = countways2(i,j-1,dp);

//     return dp[i][j]=up+left;

// }

// int countways(int m, int n){
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return countways2(m-1,n-1,dp);
// }

// int main(){

//     int m = 3;
//     int n = 2;

//     cout<<countways(m,n);
// }

//tabulation approach
#include <bits/stdc++.h>
using namespace std;

int countways2(int m, int n, vector<vector<int>>&dp){
    //base case

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) {
                dp[i][j]= 1;
                continue;
            }

            int up= 0;
            int left = 0;

            if(i>0){
                up= dp[i-1][j];
            }
            if(j>0) left = dp[i][j-1];

            dp[i][j]= up+left;
        }
    }
  
  return dp[m-1][n-1];

}

int countways(int m, int n){
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return countways2(m,n,dp);
}

int main(){

    int m = 3;
    int n = 2;

    cout<<countways(m,n);
}