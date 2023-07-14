#include<bits/stdc++.h>
using namespace std;

bool detect(int node, vector<int>adj[], int vis[]){

    vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});

    while(!q.empty()){
        int node1 = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjnode: adj[node1]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push({adjnode,node1});
            }
            else if(parent!= adjnode) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adj[]){
    int vis[V]={0};
    for(int i =0; i<V; i++){
        if(!vis[i]){
            if(detect(i,adj,vis))return true;
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