#include <bits/stdc++.h>
//https://cses.fi/problemset/task/1640/
using namespace std;

struct Tuple{
	int val;
	int pos;
};


void getTwoNumbers(int *arr, int n, int target_number){
	bool flag = true;
	int  a=0, b=n-1;

    while(a<=b){
    	if(a>b){
    		cout<<"IMPOSSIBLE"<<endl;
    		return;
		}
		
        if(arr[a]+arr[b] == target_number){
        	cout<<a+1<<" "<<b+1;
    		return;	
		}
		else if(arr[a]+arr[b-1] == target_number){
        	cout<<a+1<<" "<<b;
    		return;
    	}
    	else if(arr[a+1]+arr[b] == target_number){
        	cout<<a+2<<" "<<b+1;
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
    
	cout<<"IMPOSSIBLE"<<endl;

}

//Complejidad: O(n)
int main(){
    
    //Entrada
    int *arr, n, target_number;
    cin>>n; cin>>target_number;
    arr = new int[n];
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    
    //Output
    getTwoNumbers(arr, n, target_number);

	delete[] arr;

    return 0;
}

