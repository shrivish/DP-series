#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int ind,vector<int>& nums,set<vector<int>>&med, vector<int>&dp,int n){

        if(ind==n){
            sort(dp.begin(),dp.end());
            med.insert(dp);
            return;
        }

        dp.push_back(nums[ind]);
        solve(ind+1,nums,med,dp,n);
        dp.pop_back();

        solve(ind+1,nums,med,dp,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>dp;
        set<vector<int>>med;
        vector<vector<int>>ans;
        int n = nums.size();
        solve(0, nums, med, dp, n);
        for(auto it= med.begin(); it!= med.end(); it++){
            ans.push_back( *it);
        }
        return ans;
    }
};