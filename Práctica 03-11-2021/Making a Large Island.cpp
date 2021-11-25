#include <bits/stdc++.h>

using namespace std;

#define INF 999

int h, w, res;
int opt[4][2];
				
void inicializar(){
	opt[0][0] = 0;
	opt[0][1] = 1;
	
	opt[1][0] = 0;
	opt[1][1] = -1;
	
	opt[2][0] = 1;
	opt[2][1] = 0;
	
	opt[3][0] = -1;
	opt[3][1] = 0;
}

int DFS(vector<vector<int>> grid, int r, int c, bool visited[][999]){
    int aux = 1;
    int x = 0, y = 0;
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        x = r + opt[i][0];
        y = c + opt[i][1];
        if(x >= 0 && 
			x < h && 
			y >= 0 && 
			y < w && 
			grid[x][y] == 1 && 
			!visited[x][y]){
            	aux += DFS(grid, x, y, visited);
        }
    }
    return aux;
}

int largestIsland(vector<vector<int>>& grid) {
	
	inicializar();
	
   	if(grid.size() == 0 || grid[0].size() == 0) 
		return 0;
    h = grid.size();
    w = grid[0].size();
    
    bool aux[h][999];

    for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                aux[i][j]=false;
    
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
        	if(grid[i][j] == 0){
            	res = max(DFS(grid, i, j, aux), res);
            }
        }
    }
    
	return res == 0 ? h * w: res;    
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
	
	cout<<largestIsland(grid);
	
	return 0;
}
