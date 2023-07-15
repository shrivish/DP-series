#include<bits/stdc++.h>
using namespace std;

vector<int> canFinish(int n,int m, vector<vector<int>>& prerequisites) {

         vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count=0;

        while(!q.empty()){
            auto t = q.front();
            ans.push_back(t);
            count++;
            q.pop();

            for(auto x: adj[t]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(count==n)return ans;
        return {};
    }

    int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	vector<int> ans = canFinish(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}
