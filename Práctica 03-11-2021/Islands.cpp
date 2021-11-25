#include <bits/stdc++.h>

using namespace std;

void DFS(int r, int c, int i, int j, bool visited[][999], char mat[][999]){
	stack<int> pila1;
	stack<int> pila2;
	pila1.push(i);
	pila2.push(j);
	
	while(!pila1.empty() && !pila2.empty()){
		int cr = pila1.top(); pila1.pop();
		int cc = pila2.top(); pila2.pop();
		
		if(!visited[cr][cc]){
			visited[cr][cc] = true;
			if (cr-1 >= 0 && mat[cr-1][cc] != 'W'){
				pila1.push(cr-1);
				pila2.push(cc);
			}
            if (cr+1 < r && mat[cr+1][cc] != 'W'){
            	pila1.push(cr+1);
				pila2.push(cc);
			}
            if (cc-1 >= 0 && mat[cr][cc-1] != 'W'){
            	pila1.push(cr);
				pila2.push(cc-1);
			}
            if (cc+1 < c && mat[cr][cc+1] != 'W'){
            	pila1.push(cr);
				pila2.push(cc+1);
			}
		}
	}
}

int main(){
	
	int r,c;
	cin>>r;
	cin>>c;
	
	char mat[r][999];
	bool visited[r][999];
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; j++){
			cin>>mat[i][j];
			visited[i][j] = false;
		}
	}
	
	int cont;
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; j++){
			if(mat[i][j] == 'L' && !visited[i][j]){
				DFS(r, c, i, j, visited, mat);
				cont++;	
			}
		}
			
	}
	cout<<cont;
	
	
	
	return 0;
}
