#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int getMaximunSum(vector<int> arr, int S){
	
	int minimo = INF;
	int aux = 0;
	
	int k=(S+1)/2;	//7 -> k=4
	int k_1 = S-k;  //  -> k_1 = 3

	for(int i=0; i<k; i++){
		aux += arr[i];
		if(minimo>aux)
			minimo = aux;
		cout<<"0 "<<i<<" "<<": "<<aux<<endl;
	}
	
	int aux2 = 0;
	for(int i=k-1; i>=k-k_1; i--){
		aux2 += arr[i];
		if(minimo>aux2)
			minimo = aux2;
		cout<<k-1<<" "<<i<<": "<<aux2<<endl;
	}
	
	
	
	return minimo;
}



//Complejidad: O(n)
int main(){
    
    //Entrada
    int n, S;
    cout<<"n: ";cin>>n; 
	cout<<"S: ";cin>>S;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    
    //Output
    cout<<"Output: "<<getMaximunSum(arr, S);


    return 0;
}
