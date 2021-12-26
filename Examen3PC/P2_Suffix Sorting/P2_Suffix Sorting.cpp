#include <bits/stdc++.h>

using namespace std;

#define INF 999999
#define FOR(A,B,C) for(int i=A; i<B; i+=C)
#define FOR_bit(A,B,C) for(int a=A; a<B; a<<=C)

vector<int> arrSufijos(INF);
vector<int> arrID(INF);
vector<int> ordenActual(INF);

void llenar(int n, string s){
	FOR(0,n,1){
        arrSufijos[i] = i;
        arrID[i] = s[i];
    }
}

void actualizar(int n, int maxBytes){
	FOR_bit(1,2*n,1) {
    	
        int mitad = a/2;
        
        FOR(0,n,1){
            ordenActual[i] = arrSufijos[i] - mitad;
            if (ordenActual[i] < 0){ 
				ordenActual[i] += n; 
			}
        }
        
        vector<int> aux(maxBytes);
        
        int it;
        FOR(0,n,1){ 
        	it = arrID[ordenActual[i]];
			aux[it]++; 
		}
        
        FOR(1,maxBytes,1){
			aux[i] = aux[i]+aux[i - 1];
		}
		
		int it2;
		FOR(0,n,1){
            it2 = ordenActual[n-i-1];
            aux[arrID[it2]]--;
            it = aux[arrID[it2]];
            arrSufijos[it] = it2;
        }

        vector<int> nuevoArrID(n);
        maxBytes = 1;
        
		nuevoArrID[arrSufijos[0]] = 0;
		
        FOR(1,n,1){
        	if(arrID[arrSufijos[i]] == arrID[arrSufijos[i - 1]]){
        		int pos1 = arrSufijos[i] + mitad;
                if (pos1 > n){
					pos1 -= n; 
				}
                int pos2 = arrSufijos[i - 1] + mitad;
                if (pos2 > n){ 
					pos2 -= n; 
				}
                if (arrID[pos1] != arrID[pos2]){
					maxBytes++;
				}
			}
            else{
                maxBytes++;
            }
            
            nuevoArrID[arrSufijos[i]] = maxBytes - 1;
        }
        
        arrID = nuevoArrID;
    }
}

vector<int> obtenerArregloSufijos(string s) {
	
    int n = s.size() + 1;
    int maxBytes = 1024;
    
	llenar(n, s);
    actualizar(n, maxBytes);
    
    FOR(0,n-1,1){
		arrSufijos[i] = arrSufijos[i + 1];
	}
	
	//Debido a que se trabaja con size + 1
    arrSufijos.pop_back();
    
    
    return arrSufijos;
}

int main(){
	
	string cad;
	int querie;
	int n; //Casos
	vector<int> sufijos;
	
	while(getline(cin, cad)){
	
		sufijos = obtenerArregloSufijos(cad);
	
		cin>>n;
		for(int i=0; i<n; i++){
			
			cin>>querie;
			cout<<sufijos[querie]<<" ";
		}
		cout<<endl;
		cin.ignore();
		
		sufijos.clear();
	}
	
	
	
	return 0;
}
