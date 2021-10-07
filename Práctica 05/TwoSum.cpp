#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> resultado;
	for(int i=0; i<nums.size(); i++){
		for(int j=i; j<nums.size(); j++){
			if(nums[i]+nums[j]==target && i!=j){
				resultado.push_back(i);
				resultado.push_back(j);
				return resultado;

			}	
		}	
	}
	return resultado;
}

int main(){
	
	//Entrada
    int n, target;
    cout<<"n: ";cin>>n; 
	cout<<"target: ";cin>>target;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<int> resultado = twoSum(arr,target);
    for(int n:resultado){
    	cout<<n<<" ";
	}
    
	return 0;
}
