#include<bits/stdc++.h>
using namespace std;

void printAll(int ind, vector<int>&arr,vector<int>&dp, int n){
    
    if(ind==n){
        //print dp
        for(auto i: dp){
            cout<<i<<" ";
        }
        if(dp.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    
    //pick
    dp.push_back(arr[ind]);
    printAll(ind+1, arr, dp, n);
    dp.pop_back();

    //not pick
    printAll(ind+1, arr, dp, n);
}

int main(){
    vector<int> arr{3,1,2};
    int n = arr.size();
    vector<int>dp;
    printAll(0,arr,dp,n);
}