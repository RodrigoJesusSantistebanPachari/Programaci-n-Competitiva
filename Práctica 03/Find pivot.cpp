#include <bits/stdc++.h>

using namespace std;

int getSumaTotal(int *arr, int n){
	int cont = 0;
	for(int i=0; i<n; i++){
		cont+=arr[i];
	}
	return cont;
}

int getPivoxIndex(int *arr, int n){
	int total = getSumaTotal(arr,n);
	int cont = 0;
    for(int i=0; i<n; i++){
        if(cont == total-cont-arr[i])
        	return i;
        cont+=arr[i];
    }
    return -1;

}

//Complejidad: O(n)
int main(){
    
    //Entrada
    int *arr, n;
    cout<<"n = "; cin>>n;
    arr = new int[n];
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    //Output
    cout<<"Pivot Index: "<<getPivoxIndex(arr, n);

	delete[] arr;

    return 0;
}

