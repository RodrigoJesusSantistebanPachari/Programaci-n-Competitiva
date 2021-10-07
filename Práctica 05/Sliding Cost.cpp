#include <bits/stdc++.h>

using namespace std;

int costo(vector<int> nums, int a, int k){
	for(int i=a; i<k; i++){
		
	}
}

vector<int> SlidingCost(vector<int>& nums, int k) {
	int aux[k];
	
	for(int i=0; i<nums.size()-k+1; i++){
		cout<<costo(nums,i,k);
	}
}


int main(){
	
	//Entrada
	int n, k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<int>result = SlidingCost(arr, k);
    for(n:result)
    	cout<<n<<" ";
    
	return 0;
}
