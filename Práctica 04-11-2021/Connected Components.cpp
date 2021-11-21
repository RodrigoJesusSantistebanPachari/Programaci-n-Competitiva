#include <bits/stdc++.h>

//Decimal: 1
//Binario: 0

using namespace std;

int v,e,n;
char v_1, v_2; 
int grafo[26][26];
bool visited[26];

void resetear(){
	for(int i = 0; i< 26; i++)
		visited[i] = false;
	for(int i = 0; i< 26; i++){
		for(int j = 0; j< 26; j++){
			grafo[i][j] = 0;
		}	
	}
	
}

void busqueda(int a, int v){
    visited[v] = true;
    cout <<char(v+97)<< " ";
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = 0;adj[v].begin(); i<a != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 

int main(){
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>v; cin>>e;
		resetear();
		for(int j=0; j<e; j++){
			cin>>v_1; cin>>v_2;
			grafo[v_1-97][v_2-97] = 1;	//ASCCI
			grafo[v_2-97][v_1-97] = 1;
		}
		for(int j=0; j<v; j++){
			if (!visited[i]){
				for(int k=0; k<)
				cout<<endl;
			}
		}
		
	}
	
	return 0;
}

