#include <bits/stdc++.h>

using namespace std;

void getTwoNumbers(int *arr, int n, int target_number){
	bool flag = true;
	int  a=0, b=n-1;

    while(a<b){
    	if(a>b){
    		return;
		}
		
        if(arr[a]+arr[b] == target_number){
        	cout<<a<<" "<<b;
    		return;	
		}
		else if(arr[a]+arr[b-1] == target_number){
        	cout<<a<<" "<<b-1;
    		return;
    	}
    	else if(arr[a+1]+arr[b] == target_number){
        	cout<<a+1<<" "<<b;
    		return;
    	}
		
		if(flag){
			a++;
			flag = false;
		}
		else{
			b--;
			flag = true;
		}
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
    getTwoNumbers(arr, n, target_number);

	delete[] arr;

    return 0;
}

