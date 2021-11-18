#include <bits/stdc++.h>


using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    for (int i = cost.size()-3; i>=0; i--)
        cost[i] += min(cost[i+1], cost[i+2]);
    return min(cost[0], cost[1]);
}


int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	
	cout<<"Output: "<<minCostClimbingStairs(v);
	return 0;
}
