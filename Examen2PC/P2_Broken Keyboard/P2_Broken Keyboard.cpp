#include <bits/stdc++.h>

#define INF 999

using namespace std;  

int aux[INF];

void limpiar(){
	for(int i=0; i<INF; i++){
		aux[i] = 0;
	}
}

void brokenKeyboard(string input, int m){
	
	int resp = 0;
	int size=input.size();  
	
	int a1 = 0, a2 = 0;
	int izquierda=0,derecha=0;
	
	while(true){
		
		//Break
		if(izquierda>derecha || derecha>=size)
			break;
		
    	while(true){
    		
    		if(a1>m || derecha>=size)
    			break;
    		
       		if(aux[input[derecha]]==0) {
       			aux[input[derecha]]=1; 
				a1++;  
    			if(a1>m)     
           			break;  
       		}  
       		else {
       			aux[input[derecha]]++;  	
			}
			
         	a2++;	
        	derecha++;
        	
        	
    	}  
    	if(a2>resp) 
      		resp=a2;
    		if(derecha>=size) 
      			break;
      			
      	a1--;
		derecha++;  
		
    	while(true){  
      		aux[input[izquierda]] -- ;  
      		if(aux[input[izquierda]] == 0) 
        		break;  
      		izquierda++; 
      		a2--;  
    	}
    	
    	izquierda++; 
		
    } 
    cout<<resp<<endl; 
}



int main(){
	
	string input;
	int m;
	
	
	
	m=-1;
	while(m!=0){
		
		cin>>m;
		
		if(m==0)
			break;
		
		//Entrada
	    limpiar();
	    cin.ignore();
	    getline(cin,input);
	    
		brokenKeyboard(input, m);
    	
	}  
	return 0;  
}  
