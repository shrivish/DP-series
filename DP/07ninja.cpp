#include<bits/stdc++.h>
using namespace std;

int ninja(int last, int day, vector<vector<int>>&input, vector<vector<int>>&dp){

    if(day==0){
        int max_point = 0;
        for(int i=0; i<=2; i++){
            if(i!= last){
                max_point = max(max_point, input[0][i]);
            }
        }
        return dp[day][last]= max_point;
    }

    if(dp[day][last]!=-1) return dp[day][last];

    int max_point = 0;
    for(int i=0; i<=2; i++){
        if(i!=last){
            int activity = input[day][i]+ ninja(i, day-1, input, dp);
            max_point = max(max_point,activity);
        }
    }
    return dp[day][last]= max_point;
}

int solve(vector<vector<int>>& input, int n){
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return ninja(3,n-1, input, dp);
}

int main(){
    vector<vector<int>> input = {{10, 20, 30},{40, 50, 60},{70, 80, 90}};
    int n = input.size();
    cout<<solve(input, n);
}