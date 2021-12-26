#include<bits/stdc++.h>

#define INF 999999
#define ll long long

using namespace std;

int main(){

    int n1, n2;
    while (cin>>n1>>n2 && n1!=0 && n2!=0) {
    	
        ll n1pasos = 0;
		ll n2pasos = 0; 
        unordered_map<ll, ll> secuencia;
        ll nIT = n1;
        secuencia[nIT] = n1pasos;
        
        while(true) {
        	
        	if(nIT == 1){
        		break;
			}
        	
            n1pasos++;
            if(nIT % 2 == 0)
                nIT /= 2;

            else
                nIT = nIT * 3 + 1;
            
            secuencia[nIT] = n1pasos;
        }

        ll nIT2 = n2;
        while (true) {
        	
            if (secuencia.find(nIT2) != secuencia.end()) {
            	
                ll countNum1 = secuencia[nIT2];
                ll countNum2 = n2pasos;
                cout<<n1<<" needs "<<countNum1<<" steps, "<<n2<<" needs "<<countNum2<<" steps, ";
                cout<<"they meet at "<<nIT2<<endl;
                break;
                
            }

            if (nIT2 % 2 == 0) {
                nIT2 /= 2;
            }
            else {
                nIT2 = nIT2 * 3 + 1;
            }
            n2pasos++;
        }
    }
    return 0;
}
