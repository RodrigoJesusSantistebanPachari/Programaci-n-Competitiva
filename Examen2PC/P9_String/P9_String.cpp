//https://www.beecrowd.com.br/judge/en/problems/view/2917

#include <bits/stdc++.h>

#define INF 999999
#define MAX 999


using namespace std;

bool flag=false;

void String(int M, vector<int> &metros){
	int maximo = -INF;
	int aux = -INF;
	int idx1=0,idx2=0;
	int posx, doble_metros = M*20;

    while(true){
        	
    	if(idx1>=doble_metros)
       		break;
      	
       	int metro = M*10;
        if(idx2==metro){
			idx2=0;
			flag=true;
		}
		
    	aux=aux+metros[idx2];

        if(flag && posx==idx2)
            break;	

		
        else{
            if(maximo<aux){
                maximo=aux;
			} 
        }

        if(aux<=0){ 
            if(idx2==metro-1)
                posx=0;	
            else
                posx=idx2+1; 	
            aux=0;
        }
        
        //Incremento de indices
        idx1++;
		idx2++;
    }
    
    cout<<maximo<<endl;
}

int main(){
	
    int M=0;
    //Hasta encontrar EOF
    while(cin>>M){
    	
    	flag = false;	//Reinicio
    	
    	int cantidad_valores = M*10;
    	
        vector<int> metros(cantidad_valores);
        for(int i=0; i<M*10;i++)
            cin>>metros[i];
            
        String(M, metros);
    }

    return 0;
}
