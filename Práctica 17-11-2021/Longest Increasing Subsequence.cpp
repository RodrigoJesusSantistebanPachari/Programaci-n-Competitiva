#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
	vector <int> aux (nums.size());
	aux[0] = 1;
	for (int i=1; i<nums.size(); i++){
		aux[i] = 1;
		for(int j=0; j<i; j++){
			if(nums[i]>nums[j] && aux[i]<aux[j]+1){
				aux[i] = aux[j] + 1;
			}
		}
	}
	
	return *max_element(aux.begin(), aux.end());
	        
}


int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	
	cout<<"Output: "<<lengthOfLIS(v);
	return 0;
}
