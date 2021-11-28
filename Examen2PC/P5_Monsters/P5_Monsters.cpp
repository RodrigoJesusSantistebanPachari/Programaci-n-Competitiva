//https://cses.fi/problemset/task/1194/

#include<bits/stdc++.h>

#define INF 999999
#define MAX 2000
using namespace std;

queue<pair<int, int>> cola;
int cam[MAX][MAX];
pair<int, int> puntos[MAX][MAX], aux;
string resp;
bool flag = false;
bool flag2 = false;

void busqueda_anchura(int n, int m);

void aniadir(int n, int m){
	busqueda_anchura(n, m);
	flag2 = true;
	puntos[aux.first][aux.second] = pair<int, int>(0,0);
	cam[aux.first][aux.second] = 0;
	cola.push(aux);
	busqueda_anchura(n, m);
	
}

void res(){
	//Se muestra al revés
	if(flag){
		reverse(resp.begin(), resp.end());
		cout<<resp<< endl;
	}
	else {
		cout<<"NO"<<endl;	
	}
}


void back_track(pair<int, int> nodo_par);

void busqueda_anchura(int n, int m){
	while(!cola.empty()){
		pair<int, int> aux = cola.front(), next; 
		cola.pop();
		
		
		next = aux; 
		next.first++;
		
		 
		int pl = cam[aux.first][aux.second];
		if(pl+1<cam[next.first][next.second]){
			cam[next.first][next.second]  = pl+1;
			cola.push(next);
			puntos[next.first][next.second] = aux;
		}
		
		
		next = aux; 
		next.first--; 
		
		
		pl = cam[aux.first][aux.second];
		if(pl+1<cam[next.first][next.second]){
			cam[next.first][next.second]  = pl+1;
			cola.push(next);
			puntos[next.first][next.second] = aux;
		}
		
		
		next = aux; next.second++; 
		pl = cam[aux.first][aux.second];
		if(pl+1<cam[next.first][next.second]){
			cam[next.first][next.second]  = pl+1;
			cola.push(next);
			puntos[next.first][next.second] = aux;
		}
		
		
		next = aux;
		next.second--; 
		pl = cam[aux.first][aux.second];
		if(pl+1<cam[next.first][next.second]){
			cam[next.first][next.second]  = pl+1;
			cola.push(next);
			puntos[next.first][next.second] = aux;
		}
		
		
		if(flag2 && (aux.first == 1 || aux.second == 1 || aux.first == n || aux.second == m)){
			
			cout<<"YES"<< endl;
			cout<<cam[aux.first][aux.second]<<endl;
			
			back_track(aux);
			flag = true;
			return;
		}
		
	}
}
int main() {
	
	int n, m;
	string input;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		
		cin>>input;
		for(int j=1; j<=m; j++){
			
			cam[i][j] = INF;
			if(input[j-1]== '#') {
				cam[i][j] = 0;
			}
			if(input[j-1]== 'M') {
				cola.push(pair<int, int>(i,j)); 
				cam[i][j]  = 0;
			}
			if(input[j-1]== 'A') {
				aux.first = i; 
				aux.second = j;
			}
		}
	}
	
	aniadir(n,m);
	
	res();
}


void back_track(pair<int, int> nodo_par){
	pair<int, int> origen;
	origen = puntos[nodo_par.first][nodo_par.second];
	if(origen ==  pair<int, int>(0,0)) 
		return;
		
	if(origen.first == nodo_par.first-1) 
		resp.push_back('D');
	if(origen.first == nodo_par.first+1) 
		resp.push_back('U');
	if(origen.second==nodo_par.second-1) 
		resp.push_back('R');
	if(origen.second == nodo_par.second+1) 
		resp.push_back('L');
	
	back_track(origen);

}
