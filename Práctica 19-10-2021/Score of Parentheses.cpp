#include <bits/stdc++.h>

using namespace std;


int scoreOfParentheses(string s) {
	
	stack<int> pila;
	int cont = 0;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]== '(' ){
			pila.push(cont);
			cont = 0;
		}
		else if(s[i] == ')'){
			cont = pila.top()+max(cont*2,1);
			pila.pop();
		}
	}
	
	return cont;
	
}


int main(){
	
	//Entrada
	string s;
    cin>>s;
    
    cout<<scoreOfParentheses(s);
	return 0;
}
