#include <bits/stdc++.h>

using namespace std;


long long int max(long int a, long int b){
	if(a<b)
		return b;
	return a;
}

long int MaximunSubarraySum(vector<long int>& nums, int a, int b) {
	long int maxi = -99999999;
	long int sum = 0;
	for (int i=a-1; i<b; i++){
		sum = max(nums[i], nums[i]+sum);
		maxi = max(maxi,sum);
	}
	
	if(maxi<0)
		return 0;
	return maxi;
}

int main(){
	
	//Entrada
	int n, q;
    cin>>n;
    cin>>q;
    vector<long int> arr(n);
    vector<long int> resp;
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k,a,b;
    for(int i=0; i<q; i++){
        cin>>k;
        cin>>a;
        cin>>b;
        
        if(k==1)
        	arr[a-1] = b;
		else
			resp.push_back(MaximunSubarraySum(arr,a,b));	
	}
	
	for(long int n: resp){
		cout<<n<<endl;
	}
    
	return 0;
}
