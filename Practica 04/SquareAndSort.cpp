#include <bits/stdc++.h>

using namespace std;

void squareSorted(vector<int> arr, int n){
	
	//Square
	for(int i=0; i<n; i++){
		arr[i] = arr[i]*arr[i];
	}
	
	//Sort
	sort(arr.begin(),arr.end() );
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

//Complejidad: O(n*log(n))
int main(){
    
    //Entrada
    int n, target_number;
    cout<<"n = "; cin>>n;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    
    //Output
    squareSorted(arr, n);

    return 0;
}
