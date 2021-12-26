#include <bits/stdc++.h>

using namespace std;

#define INF 9999
#define v vector
#define m map
#define FOR(i,A,B,C) for(auto i=A; i<B; i+=C)
#define FOR_TO(A,B) for(auto A : B)
#define CON 4


int sem(int dia){
	return (dia+1)%7;
}

void printResultado(m<int, set<string>>& arrAux, int cont, int n){
	for(auto val = arrAux.rbegin(); 
		cont<n && val != arrAux.rend(); 
		val++){
		        
		FOR_TO(palabra, val->second){
		    cout<<palabra<<" ";
			cout<<val->first<<endl;
		    cont++;
			          
		}
	}
}

void actDicc(v<string> palabras[], int dia, m<string, int> &dicc){
	FOR(i,0,palabras[dia].size(),1){
      		
		string words_vector = palabras[dia][i];
      		
	    dicc[words_vector] -= 1;
	       
		if(dicc[words_vector] == 0){
	        dicc.erase(words_vector);
		}
	}
}

int main(){
		
	v<string> palabras[20];
	
	int dia = 0;
    string cad; 
    string palabra;
    int cont = 0;
    
    //Maps
   	m<string, int> dicc;
	m<int, set<string>> arrAux;
    
    while(cin>>cad){
    	
        if(cad=="<text>"){
        	
        	actDicc(palabras, dia, dicc);
		
		    palabras[dia].clear();	
		    cin>>palabra;
		    
		    while(palabra != "</text>"){
		    	
		        if(palabra.size() >= CON){
		        	
		            palabras[dia].push_back(palabra);
		            dicc[palabra]++;
		            
		        }
		        
		        cin>>palabra;
		    }
		    
		    dia = sem(dia);   
			 
		}
		
        else{
        	int n; string aux; 
			cin>>n>>aux;
		
		    arrAux.clear();
		
		    FOR_TO(value,dicc){
		        if(value.second > 0){
		            arrAux[value.second].insert(value.first);
				}
		    }
		
			cont=0;
		    cout<<"<top "<<n<<">"<<endl;
		    
		    printResultado(arrAux, cont, n);
		    
		    cout<<"</top>"<<endl;   
		}
    }
    
    return 0;
}
