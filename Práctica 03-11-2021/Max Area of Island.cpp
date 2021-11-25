#include <bits/stdc++.h>

using namespace std;

int n,m;

int sum(int i, int j, vector<vector<int>>& grid) {
    if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) 
		return 0;
    grid[i][j] = 0;
    return 1 + sum(i-1, j, grid) + sum(i, j-1, grid) + sum(i+1, j, grid) + sum(i, j+1, grid);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int ans = 0;
    n = grid.size();
	m = grid[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if (grid[i][j]){
				ans = max(ans, sum(i, j, grid));
			}	
		}
	}
    return ans;
}

int main(){
	
	int f,c;
	cout<<"f: "; cin>>f;
	cout<<"c: "; cin>>c;
	vector<vector<int>> grid;
	
	for(int i=0; i<f; ++i){
		vector<int> aux(c);
		for(int j=0; j<c; j++){
			cin>>aux[j];
		}
		grid.push_back(aux);
	}
	
	cout<<maxAreaOfIsland(grid);
	
	return 0;
}
