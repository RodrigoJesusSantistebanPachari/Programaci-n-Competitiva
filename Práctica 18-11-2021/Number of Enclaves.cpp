#include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int>>&grid,int i,int j){
        int r=grid.size();
        int c=grid[0].size();

        if(i<0||j<0||i>=r||j>=c||grid[i][j]!=1) //base condition
            return;

        grid[i][j]=2;

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    
int numEnclaves(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0 || i==r-1 || j==c-1)
                    dfs(grid,i,j);
            }
        }
        int res=0; //increment count everytime you see 1
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    res++;
            }
        }
        return res;
    }

int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	vector<int> v(n);
	vector<vector<int>> grid;
		
	
	for(int i=0; i<n; i++){
		grid.push_back(v);
		for(int j=0; j<n; j++){
			cin>>grid[i][j];
		}
	}

	
	cout<<"Output: "<<numEnclaves(grid);
	
	return 0;
}
