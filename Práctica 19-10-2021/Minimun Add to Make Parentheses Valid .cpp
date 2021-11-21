#include <bits/stdc++.h>

using namespace std;


int minAddToMakeValid(string s) {
	
	stack<char> pila;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='(')
			pila.push('(');
		else if(s[i] == ')'){
			if(pila.size() == 0)
				pila.push(')');
			else if(pila.top() == ')')
				pila.push(')');
			else
				pila.pop();
		}
	}
	
	return pila.size();
	
}


int main(){
	
	//Entrada
	string s;
    cin>>s;
    
    cout<<minAddToMakeValid(s);
	return 0;
}
