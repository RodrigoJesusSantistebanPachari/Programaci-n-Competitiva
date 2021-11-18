#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
	int aux[n+2];
	aux[0] = 1;
	aux[1] = 2;
	for(int i=2; i<n; i++)
       aux[i] = aux[i - 1] + aux[i - 2];
	return aux[n-1];
}

int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	cout<<"Output: "<<climbStairs(n);
	return 0;
}
