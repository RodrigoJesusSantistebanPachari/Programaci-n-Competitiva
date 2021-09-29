#include <bits/stdc++.h>

using namespace std;

int getMaximunSum(vector<int> arr, int n, int k){
	
	int maximo = 0;
	int aux;

	aux = accumulate(arr.begin(), arr.begin()+k, 0);
	
	for(int i=0; i<n-k+1; i++){
		cout<<i<<" "<<i+k<<" "<<": "<<aux<<endl;
		if(maximo<aux)
			maximo = aux;
		aux += arr[i+k];
		aux -= arr[i];
	}
	
	return maximo;
}



//Complejidad: O(n)
int main(){
    
    //Entrada
    int n, k;
    cout<<"n: ";cin>>n; 
	cout<<"k: ";cin>>k;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    
    //Output
    cout<<"Output: "<<getMaximunSum(arr, n, k);


    return 0;
}
