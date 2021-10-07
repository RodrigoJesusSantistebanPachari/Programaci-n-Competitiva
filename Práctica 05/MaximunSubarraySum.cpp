#include <bits/stdc++.h>

using namespace std;

long long int max(long long int a, long long int b){
	if(a<b)
		return b;
	return a;
}

long long int MaximunSubarraySum(vector<long long int>& nums) {
	long long int maxi = nums[0];
	long long int sum = nums[0];
	for (long long int i=1; i<nums.size(); i++){
		sum = max(nums[i], nums[i]+sum);
		maxi = max(maxi,sum);
	}
	
	return maxi;
}


int main(){
	
	//Entrada
    int n;
    cin>>n; 
    vector<long long int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<MaximunSubarraySum(arr);
    
	return 0;
}
