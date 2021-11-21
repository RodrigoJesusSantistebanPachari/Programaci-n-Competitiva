#include <bits/stdc++.h>

using namespace std;


vector<int> EvenAndOdd(vector<int> &S){
	
	sort(S.begin(), S.end());
	stack<int> pila;
	queue<int> cola;
	for(int n:S){
		if(n%2==0)
			cola.push(n);
		else
			pila.push(n);
	}
	
	vector<int> resultado;
	
	while(!cola.empty()){
		resultado.push_back(cola.front());
		cola.pop();
	}
	
	while(!pila.empty()){
		resultado.push_back(pila.top());
		pila.pop();
	}
	
	
	return resultado;
}


int main(){
	
	int n;
	cin>>n;
	vector<int> S(n);
	for(int i=0; i<n; ++i){
		cin>>S[i];
	}
	
	vector<int> resp = EvenAndOdd(S);
	for(int n:resp)
		cout<<n<<endl;

	
	return 0;
}
