#include <bits/stdc++.h>
using namespace std;

	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		for (auto it : adj[node]) {
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
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