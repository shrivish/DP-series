#include<bits/stdc++.h>
using namespace std;
 bool dfs(int node,int col, vector<vector<int>>& graph, vector<int>&color){
        color[node]=col;

        for(auto adjnode:graph[node]){
            if(color[adjnode]==-1){
                if(dfs(adjnode,!col,graph,color)==false)return false;
            }
            else if(color[adjnode]==col){
                return false;
            }
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
       int V = graph.size(); 
       vector<int> color(V, -1); 

       for(int i=0; i<V; i++){
           if(color[i]==-1){
               if(dfs(i,0,graph,color)==false) return false;
           }
       }
       return true;
    }

    