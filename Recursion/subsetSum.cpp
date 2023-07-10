#include<bits/stdc++.h>
using namespace std;

void solve(int ind,vector<int>& nums, vector<int>&dp,int n,int sum,vector<int>&ans){

        if(ind==n){
            ans.push_back(sum);
            return;
        }

        solve(ind+1,nums,dp,n,sum+nums[ind],ans);

        solve(ind+1,nums,dp,n,sum,ans);
}

vector<int> subsetsWithDup(vector<int>& nums ,int n) {
        sort(nums.begin(), nums.end());
        vector<int>dp;
        vector<int>ans;
        solve(0, nums, dp, n , 0,ans);
        sort(ans.begin(),ans.end());
        return ans;
}

int main() {
  vector < int > arr{3,1,2};
  vector < int > ans = subsetsWithDup(arr, arr.size());
  sort(ans.begin(), ans.end());
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}