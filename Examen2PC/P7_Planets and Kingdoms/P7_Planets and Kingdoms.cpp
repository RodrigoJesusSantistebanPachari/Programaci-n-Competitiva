//https://cses.fi/problemset/task/1683/

#include <bits/stdc++.h>

#define INF 99999
#define MAX 999

using namespace std;

void busqueda_profundidad(vector<vector<int>>& matriz_adyacencia, vector<bool>& visitados, vector<int>& orden, int act) {
    if (visitados[act])
        return;
        
    visitados[act] = true;
    
    for (int a : matriz_adyacencia[act])
        busqueda_profundidad(matriz_adyacencia, visitados, orden, a);
        
    orden.push_back(act);
}

void busqueda_profundidad2(const vector<vector<int>>& matriz_adyacencia, vector<int>& componentes, int act, int k) {
    if (componentes[act])
        return;
        
    componentes[act] = k;
    
    for (int a : matriz_adyacencia[act]) {
        busqueda_profundidad2(matriz_adyacencia, componentes, a, k);
    }
}

int main(){
	
    int n, m;
    int a, b;
    cin>>n; cin>>m;
	
    vector<vector<int>> matriz_adyacencia(n + 1); 
	vector<vector<int>> reversa(n + 1);
    
    //Inputs
    for (int i = 0; i < m; i++) {
        cin>>a; cin>>b;
        matriz_adyacencia[a].push_back(b);
        reversa[b].push_back(a);
    }

	//Vectores auxiliares
    vector<int> orden;
    vector<bool> visitados(n + 1, false);
    
    
    for (int i = 1; i <= n; i++) {
        if (visitados[i])
            continue;
        busqueda_profundidad(matriz_adyacencia, visitados, orden, i);
    }

    vector<int> componentes(n + 1);
    reverse(orden.begin(), orden.end());

    int k = 0;
    for (auto a : orden) {
        if (componentes[a])
            continue;
        k++;
        busqueda_profundidad2(reversa, componentes, a, k);
    }

	//Salida
    cout<<k<<endl;
    for (int i = 1; i <= n; i++)
        cout<<componentes[i]<<" ";
    cout<<endl;
}
