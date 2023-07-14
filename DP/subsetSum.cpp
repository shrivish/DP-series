#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int target, vector<int>&arr){

    //base case
    if(target==0)return true;

    if(n==0) return arr[0]=target;

    bool nottake = solve(n-1, target, arr);

    bool take = false;
    if(target>=arr[n]){
        take = solve(n-1, target-arr[n], arr);
    }

    return take || nottake;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (solve(n, k, arr))
        cout << "Subset found";
    else
        cout << "Subset found";
}

// tabulation