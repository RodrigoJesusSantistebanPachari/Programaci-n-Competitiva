#include <bits/stdc++.h>

using namespace std;

void getThreeNumbers(int *arr, int n, int target_number, int a, int b, int c){
	cout<<a<<" "<<b<<" "<<c<<endl;
	if(a>=b || b>=c || c>=n || a<0){
		return;
	}
	else if(arr[a]+arr[b]+arr[c] == target_number){
		cout<<"gaaaa";
		cout<<a<<" "<<b<<" "<<c<<endl;
		return;
	}
	else{
		getThreeNumbers(arr, n, target_number, a, b+1, c);
		getThreeNumbers(arr, n, target_number, a, b-1, c);
		getThreeNumbers(arr, n, target_number, a+1, b, c);
		getThreeNumbers(arr, n, target_number, a-1, b, c);
		getThreeNumbers(arr, n, target_number, a, b, c+1);
		getThreeNumbers(arr, n, target_number, a, b, c-1);
	}
	
}

//Complejidad: O(n)
int main(){
    
    //Entrada
    int *arr, n, target_number;
    cout<<"n = "; cin>>n;
    arr = new int[n];
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<"target number: "; cin>>target_number;
    
    //Output
    getThreeNumbers(arr, n, target_number, 0, n/2 ,n-1);

	delete[] arr;

    return 0;
}

