#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int>adj[]){
    int indegree[V]={0};
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0; i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    int count =0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count ++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    
    if(count==V)return false;
    return true;
}

int main() {

	vector<int> adj[6] = {{},{},{1,2},{3},{2,0},{4,5}};
	int V = 6;

	bool ans = isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}