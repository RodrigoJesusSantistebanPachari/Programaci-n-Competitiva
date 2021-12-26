#include <bits/stdc++.h>

using namespace std;

#define INF 999999

vector<int> digitos(1000001, 0);

void llenar(){
	
    int tam = 0;
    int actTam = 0;
    
    
    long double factorACtual = 1;
    
    digitos[0] = 1;
    
    for (int i = 1; i <= 1000000; i++) {

        if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) {
            actTam++;
        }
        
        long double shortFactor = (long double)i / (pow(10, actTam));
        factorACtual *= shortFactor;
        tam += actTam;

        if (factorACtual > 10) {
            factorACtual /= 10;
            tam++;
        }
        digitos[i] = tam + 1;
    }
}

int main(){
	
    llenar();
    
    int num;
    while (cin >> num) {
        cout << digitos[num] << endl;
    }
    return 0;
}
