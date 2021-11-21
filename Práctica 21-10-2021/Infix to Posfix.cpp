#include <bits/stdc++.h>

using namespace std;


string InfixToPostfix(string &S){
	
	string postfix = "";	
	stack<char> pila;
	for(char n:S){
		if(n =='+' || n == '-'){
			while(!pila.empty()){
				if(pila.top() == '(')
					break;
				postfix+=pila.top();
				pila.pop();
			}
			pila.push(n);
		}
		else if(n == '*' || n=='/'){
			while(!pila.empty()){
				if(pila.top()=='+' || pila.top()=='-' || pila.top() == '(')
					break;
				postfix+=pila.top();
				pila.pop();
			}
			pila.push(n);
		}
		else if(n=='^'){
			while(!pila.empty()){
				if(pila.top()=='+' || pila.top()=='-' || pila.top()=='*' || pila.top()=='/'|| pila.top() == '(')
					break;
				postfix+=pila.top();
				pila.pop();
			}
			pila.push(n);
		}
		
		else if(n=='('){
			pila.push(n);
		}
		else if(n==')'){
			while(pila.top() != '('){
				postfix+=pila.top();
				pila.pop();
			}
			pila.pop();
		}
		
		else{
			postfix += n;
		}
	}
	
	while(!pila.empty()){
		postfix+=pila.top();
		pila.pop();
	}
	
	return postfix;
}


int main(){
	
	int n;
	cin>>n;
	vector<string> S(n);
	for(int i=0; i<n; ++i){
		cin>>S[i];
	}
	for(int i=0; i<n; ++i){
		cout<<InfixToPostfix(S[i])<<endl;
	}

	
	return 0;
}
