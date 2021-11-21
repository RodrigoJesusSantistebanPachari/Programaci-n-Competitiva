#include <bits/stdc++.h>

using namespace std;


void merge(vector<vector<int>> &V){
	priority_queue<int> pq;
	for(int i=0; i<V.size(); i++){
		for(int j=0; j<V[i].size(); j++){
			pq.push(V[i][j]);
		}
	}
	
	while (! pq.empty() ) {
	    cout << pq.top() << " ";
	    pq.pop();
	}	
	
}


int main(){
	
	vector<vector<int>> v;
	vector<int> v1 = {1,2,4,5};
	vector<int> v2 = {1,5,9};
	vector<int> v3 = {2,8,9};
	v.push(v1);
	v.push(v2);
	v.push(v3);
	
	merge(v);
	
	

	
	return 0;
}
