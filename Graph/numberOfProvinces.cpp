#include<bits/stdc++.h>
using namespace std;

void solve(int s,vector<vector<int>> &g,vector<bool> &v){
    if(v[s])return;
    v[s] = true;
    for(auto &i: g[s]){
        solve(i,g,v);
    }
}
int numProvinces(vector<vector<int>>& v) {
        int n = v.size(),i,j;
        vector<vector<int>> g(n);
        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                if(v[i][j]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<bool> vis(n);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                solve(i,g,vis);
            }
        }
        return ans;
}

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << numProvinces(adj) << endl;
        
    return 0;
}
