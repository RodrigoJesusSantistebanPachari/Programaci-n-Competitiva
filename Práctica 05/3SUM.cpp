#include <bits/stdc++.h>

using namespace std;

void push(vector<int>& arr, int a, int b, int c){
	if(a<=b && b<=c){
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
	}
	else if(b<=a && a<=c){
		arr.push_back(b);
		arr.push_back(a);
		arr.push_back(c);
	}
	
	else if(b<=c && c<=a){
		arr.push_back(b);
		arr.push_back(c);
		arr.push_back(a);
	}
	
	else if(c<=a && a<=b){
		arr.push_back(c);
		arr.push_back(a);
		arr.push_back(b);
	}
	
	else if(c<=b && b<=a){
		arr.push_back(c);
		arr.push_back(b);
		arr.push_back(a);
	}
	
	else{
		arr.push_back(a);
		arr.push_back(c);
		arr.push_back(b);
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	
	vector<vector<int>> result;
	
	if(nums.size()<3)
		return result;
	
	vector<int> aux;
	bool arr[nums.size()];
	for(int i=0; i<nums.size();i++)
		arr[i] = false;
	
	sort(nums.begin(),nums.end());
	
	for(int i=0; i<nums.size(); i++){
		for(int j=0; j<nums.size()-1; j++){
			if(i!=j && i!=j+1 && -1*nums[i]==(nums[j]+nums[j+1])){
				push(aux,nums[i], nums[j], nums[j+1]);
				result.push_back(aux);
				aux.clear();
			}
		}
		
	}
	
	auto end = result.end();
    for (auto it = result.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    result.erase(end, result.end());

	return result;
}

int main(){
	
	//Entrada
	int n;
    cin>>n;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
   	vector<vector<int>> arr2 = threeSum(arr);
   	
   	for(int i=0; i<arr2.size(); i++){
		for(int j=0; j<arr2[i].size(); j++){
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
    
	return 0;
}
