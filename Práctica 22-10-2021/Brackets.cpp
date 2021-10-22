#include <bits/stdc++.h>

using namespace std;


int solution(string &S){
	
	stack<char> pila;
	for(char n:S){
		if(n=='['|| n=='(' || n=='{')
			pila.push(n);
		else if(!pila.empty()){
			if((n==']' && pila.top() == '[') ||
				(n=='}' && pila.top() == '{') ||
				(n==')' && pila.top() == '(') )
					pila.pop();
		}
		else{
			pila.push(n);
		}
	}

	if(pila.empty())
		return 1;
	else
		return 0;	
	
}


int main(){
	
	//Entrada
	string S;
    cin>>S;
    
    cout<<solution(S);
	return 0;
}
