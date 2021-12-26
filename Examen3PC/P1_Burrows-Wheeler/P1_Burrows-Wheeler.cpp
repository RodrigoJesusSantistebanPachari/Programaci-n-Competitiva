#include <bits/stdc++.h>

using namespace std;

#define INF 999999
#define v vector
#define FOR(i,A,B,C) for(int i=A; i<B; i+=C)
#define FOR_bit(a,A,B,C) for(int a=A; a<B; a<<=C)

v<int> arr;  
v<int> sufijos;        
v<int> LCP; 
string T;
int n;
string Total;

void redimensionar(){
	T = Total;
	n = T.size();
				
    sufijos.resize(n);
    iota(sufijos.begin(), sufijos.end(), 0);  
    arr.resize(n);
}




void contar(int tam) {               
    int maximo = max(300, n);              
    v<int> aux(maximo, 0);
	FOR(i,0,n,1){
		++aux[i + tam < n ? arr[i + tam] : 0];	
	}
	
	int sum = 0;
	FOR(i,0,maximo,1){
        int t = aux[i];
        aux[i] = sum;
        sum += t;
    }
    
    v<int> tempsufijos(n);
    
    FOR(i,0,n,1)
        tempsufijos[aux[sufijos[i] + tam < n ? arr[sufijos[i] + tam] : 0]++] = sufijos[i];
        
    swap(sufijos, tempsufijos);  
}

void contAux(){
	FOR_bit(k,1,n,1) {          
        contar(k); 
        contar(0);  
        vector<int> temparr(n);
        int r = 0;
        temparr[sufijos[0]] = r;    
		FOR(i,1,n,1){
			
			int tmp = ((arr[sufijos[i]] == arr[sufijos[i - 1]]) && (arr[sufijos[i] + k] == arr[sufijos[i - 1] + k]));
			
			temparr[sufijos[i]] = tmp? r: ++r;
		}
            
        swap(arr, temparr);          
        if (arr[sufijos[n - 1]] == n - 1) 
			break;  
    }
}

void sol() {
		
	redimensionar();

    FOR(i,0,n,1)
		arr[i] = T[i];  
	
	contAux();
}


void constuirLCP() {
    vector<int> Phi(n);
    vector<int> PLCP(n);
    PLCP.resize(n);
    Phi[sufijos[0]] = -1;                     
    for (int i = 1; i < n; ++i)          
        Phi[sufijos[i]] = sufijos[i - 1];           
    for (int i = 0, L = 0; i < n; ++i) {  
        if (Phi[i] == -1) {
            PLCP[i] = 0;
            continue;
        }  
        while ((i + L < n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L]))
            ++L;  
        PLCP[i] = L;
        L = max(L - 1, 0);  
    }
    LCP.resize(n);
    for (int i = 0; i < n; ++i)  
        LCP[i] = PLCP[sufijos[i]];    
}


int main() {
	
    while (getline(cin, Total)) {
        int n = Total.size();
        Total += Total;
        Total.pop_back();  
                       
        Total += char(9);
		 
		sol();
		constuirLCP();
		 
        for (auto i : sufijos) {
            if (i >= n) 
				continue;
            cout << Total[i + n - 1];
        }
        cout << endl;
    }

    return 0;
}
