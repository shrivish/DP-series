#include <bits/stdc++.h>
using namespace std;

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = accumulate(nums.begin(),nums.end(),0);
        //if sum is odd
        if(totsum%2!=0)return false;
        else{
            int k = totsum/2;
            vector<bool>prev(k+1,false);
            prev[0]=true;
        
            if(nums[0]<=k){
                prev[nums[0]]=true;
            }

            for(int ind =1; ind<n; ind++){
                vector<bool>curr(k+1,false);
                for(int target = 1; target<=k; target++){
                    bool taken = false;
                    if(nums[ind]<=target){
                        taken = prev[target-nums[ind]];
                    }
                    bool nottake = prev[target];
                    curr[target]= nottake||taken;
                }
                prev=curr;
            }
            return prev[k];

        }
    }

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();
    if (canPartition(arr))
        cout << "can be partitioned into two equal subsets";
    else
        cout << "cannot be partitioned into two equal subsets";
}