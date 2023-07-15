#include <bits/stdc++.h>
using namespace std;

	bool dfs(int node, vector<int> adj[], int vis[], int path[]) {
		vis[node]=1;
		path[node]=1;
		for(auto it: adj[node]){
			if(!vis[it]){
				if(dfs(it,adj,vis,path)==true)return true;
			}
			else if(path[it]){
				return true;
			}
		}
		path[node]=0;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V]={0};
		int path[V]={0};
		for(int i=0; i<V; i++){
			if(!vis[i]){
				if(dfs(i,adj,vis,path)==true)return true;
			}
		}
		return false;
	}



int main() {

	vector<int> input[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	
	bool ans = isCyclic(V, input);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}

// or i can use only one vector array and then mark it as 1 as visited and mark it as 2 for path visited.