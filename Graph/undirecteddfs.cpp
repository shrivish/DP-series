#include<bits/stdc++.h>
using namespace std;

bool dfs(int vis[], vector<int>adj[], int parent, int node){
    vis[node] = 1; 
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(vis, adj, node,adjacentNode) == true) 
                    return true; 
            }
            else if(adjacentNode != parent) return true; 
        }
        return false; 
}

bool isCycle(int V, vector<int>adj[]){
    int vis[V]={0};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(dfs(vis, adj, -1, i)==true)return true;
        }
    }

    return false;
}

int main() {
    
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}