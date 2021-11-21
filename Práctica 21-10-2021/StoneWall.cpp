#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> &H){	
	int stones = 0;
    stack<int> pila;

    for (int h: H) {
        while (!pila.empty() && h < pila.top()) 
            pila.pop();
            
        if (pila.empty() || h > pila.top()) {
            pila.push(h);
            stones++;
        }
    }
    return stones;
}


int main(){
	
	//Entrada
	int n;
	cin>>n;
	vector<int> S(n);
	for(int i=0; i<n; ++i){
		cin>>S[i];
	}

	cout<<solution(S);
	
	return 0;
}
