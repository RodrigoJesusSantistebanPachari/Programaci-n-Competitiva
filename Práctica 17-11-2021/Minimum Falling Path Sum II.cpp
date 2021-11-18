#include <bits/stdc++.h>


using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
	int INF = 999999; 
	for (int i=1; i<grid.size(); i++)
    	for (int j=0; j <grid[i].size(); j++) {
        	int m = INF;
    		for (int k = 0; k < grid[i].size(); k++) {
        		if (k == j) 
		  			continue;
          		m = min(m, grid[i - 1][k]);
        	}
        grid[i][j] += m;
    }
    return *min_element(begin(grid.back()), end(grid.back()));     
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
		
	
	cout<<"Output: "<<minFallingPathSum(grid);
	return 0;
}
