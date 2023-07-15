#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<int>adj[],stack<int>&s ){
    vis[node]=1;
    for(auto adjnode: adj[node]){
        if(!vis[adjnode]){
            dfs(adjnode, vis,adj,s);
        }
    }
    s.push(node);
}

vector<int>topoSort(int V, vector<int>adj[]){
    int vis[V]={0};
    stack<int>s;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i,vis,adj,s);
        }
    }

    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	vector<int> ans = topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}