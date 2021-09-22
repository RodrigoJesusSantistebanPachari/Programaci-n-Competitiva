#include <bits/stdc++.h>

using namespace std;


int getTotal(vector<int> arr, vector<int> aux){
	int total = aux[0];
	for(int c: aux)
		total += (c*(c-1))/2;
	return total;
}

int getSubarraySumsDivisiblebyK(vector<int> arr, int k){
	vector<int> aux(k);
	int sum=0;
	for(int n:arr){
		sum += (k+(n%k)) % k;
		aux[sum%k]+=1;
	}
	
	return getTotal(arr,aux);
}

int main(){
    
    int n, k;
    cout<<"k: ";cin>>k;
    cout<<"n: ";cin>>n;
    vector<int> arr(n);
    //Input
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<getSubarraySumsDivisiblebyK(arr,k);
    

    return 0;
}
