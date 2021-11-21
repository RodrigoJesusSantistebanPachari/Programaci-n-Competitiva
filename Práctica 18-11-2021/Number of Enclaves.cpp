#include <bits/stdc++.h>

using namespace std;


int main(){
	
	vector<int> v(n);
	vector<vector<int>> grid;
		
	
	for(int i=0; i<n; i++){
		grid.push_back(v);
		for(int j=0; j<n; j++){
			cin>>grid[i][j];
		}
	}
		
	
	cout<<"Output: "<<minFallingPathSum(grid);
	
	return 0;
}
