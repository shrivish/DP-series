#include<bits/stdc++.h>
using namespace std;

    void printAll(int ind, vector<int>&nums,vector<int>&dp, int n, vector<vector<int>>&ans){
    
        if(ind==n){
            //print dp
            ans.push_back(dp);
            return;
        }
        
        //pick
        dp.push_back(nums[ind]);
        printAll(ind+1, nums, dp, n,ans);
        dp.pop_back();

        //not pick
        printAll(ind+1, nums, dp, n, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>dp;
        printAll(0,nums,dp,n,ans);
        return ans;
    }

    int main(){
        vector<int>nums{1,2,3};
        subsets(nums);
    }
