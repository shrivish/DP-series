#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans,vector<vector<int>>& image, int row, int col, int color,int prevcolor,int delrow[], int delcol[]){
        ans[row][col]= color;
        int n = image.size();
        int m = image[0].size();

        for(int i= 0; i<4; i++){
            int nrow= row+delrow[i];
            int ncol = col+ delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == prevcolor && ans[nrow][ncol] != color){
                dfs(ans,image,nrow,ncol,color,prevcolor,delrow,delcol);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;
        int prevcolor= image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(ans,image,sr,sc,color,prevcolor,delrow,delcol);
        return ans;
    }

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	vector<vector<int>> ans = floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}