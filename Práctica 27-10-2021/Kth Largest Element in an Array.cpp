#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k){
	
	priority_queue<int> pq;
	for(int n:nums){
		pq.push(n);
	}
	
	int aux = nums.size()-k;
	
	while((k-1)!=0){
		pq.pop();
		k--;
	}
	
	return pq.top();   
}

int main(){
	
	int n;
	cout<<"n: "; cin>>n;
	vector<int> nums(n);
	for(int i=0; i<n; ++i)
		cin>>nums[i];
	
	int k;
	cout<<"k: "; cin>>k;
	
	cout<<findKthLargest(nums, k);
	
	return 0;
}
