#include <bits/stdc++.h>

using namespace std;


int evalRPN(vector<string>& tokens) {
	
	stack<int> pila;
	int aux1, aux2;
	for(int i=0; i<tokens.size(); i++){
		if(tokens[i] == "+"){
			aux1 = pila.top();
			pila.pop();
			aux2 = pila.top();
			pila.pop();
			pila.push(aux1+aux2);
		}
		else if(tokens[i] == "-"){
			aux1 = pila.top();
			pila.pop();
			aux2 = pila.top();
			pila.pop();
			pila.push(aux2-aux1);
		}
		else if(tokens[i] == "/"){
			aux1 = pila.top();
			pila.pop();
			aux2 = pila.top();
			pila.pop();
			pila.push(aux2/aux1);
		}
		else if(tokens[i] == "*"){
			aux1 = pila.top();
			pila.pop();
			aux2 = pila.top();
			pila.pop();
			pila.push(aux1*aux2);
		}
		else{
			pila.push(stoi(tokens[i]));			
		}
		
	}
	return pila.top();
	
}


int main(){
	
	//Entrada
	int n;
    cin>>n;
    vector<string> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<evalRPN(arr);
	return 0;
}
