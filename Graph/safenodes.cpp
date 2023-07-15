    #include<bits/stdc++.h>
    using namespace std;
    
    bool dfs(int node,vector<int>adj[],int vis[], int path[], int check[]){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(int adjnode: adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,adj,vis,path,check)==true){
                    check[adjnode]=0;
                    return true;
                }
            }
            else if(path[adjnode]){
                check[adjnode]=0;
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }

    vector<int> SafeNodes(int V, vector<int>adj[]) {
       
        int vis[V]={0};
        int path[V]={0};
        int check[V]={0};
        vector<int>safenodes;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj,vis,path,check);
            }
        }

        for(int it=0; it<V; it++){
            if(check[it]){
                safenodes.push_back(it);
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }

    int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	vector<int> safeNodes = SafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}