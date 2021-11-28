//https://www.beecrowd.com.br/judge/en/problems/view/1701
#include <bits/stdc++.h>

using namespace std;

long long int fibonacciIterativo(long long int n1, long long int n2, int N, long long int mod){
  	
  	vector<long long int> aux1;
  	vector<long long int> aux2;
  	
	long long int actual=1, siguiente=1, tmp=0;
	
	if(n1==1){
		aux1.push_back(1);
	}
	else if(n1==0){
		aux1.push_back(0);
		if(N>1)
			aux1.push_back(1);
	}
	
	if(n2==1){
		aux2.push_back(1);
	}
	else if(n2==0){
		aux2.push_back(0);
		if(N>1)
			aux2.push_back(1);
	}
	
	
	for(long long int i=1; i<n1+N-1; i++){
	
		if(actual >= mod || siguiente >= mod){
	      actual = actual%mod;
	      siguiente = siguiente%mod;
	    }
	
		tmp = actual;
    	actual = siguiente;
    	siguiente = siguiente + tmp;
    	
		if(i>n1-2){
    		aux1.push_back(actual);
		}
	}

	actual=1; siguiente=1; tmp=0;
	for(long long int i=1; i<n2+N-1; i++){
		
		if(actual >= mod || siguiente >= mod){
	      actual = actual%mod;
	      siguiente = siguiente%mod;
	    }
		
   		tmp = actual;
    	actual = siguiente;
    	siguiente = siguiente + tmp;
    	
    	if(actual >= mod || siguiente >= mod){
	      actual = actual%mod;
	      siguiente = siguiente%mod;
	    }
    	
    	
    	if(i>n2-2){
    		aux2.push_back(actual);
		}
	}

	long long int sum = 0;
	for(int i=0; i<aux1.size(); i++){
		sum+=(aux1[i]*aux2[i]);
		if(sum >= mod){
	    	sum = sum %  mod;
    	}
	}

	return sum;
}

int main(){
	
	long long int A,B,N;
	
	do{
		cin>>A; cin>>B; cin>>N;
		
		if((A==0 && B==0 && N==0)){
			break;
		}
		cout<<fibonacciIterativo(A,B,N, 1000000007)<<endl;

		
	}while(!(A==0 && B==0 && N==0));	

	
	return 0;
}
