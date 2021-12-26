#include <bits/stdc++.h>

using namespace std;

#define vll vector<ll> 

const int MOD = 1000000007;

int main() {
	
	long long n;
	long long t;
	long long a;
	long long b;
	long long c;
	
	cin>>n>>t>>a>>b>>c;
	
	vector<long> v(n);
	cin >> v[0];
	
	for (int i = 1; i < n; i++) {
		v[i] = (v[i - 1] * a + b) % c + 1;
	}
	
	sort(v.begin(), v.end());
	
	long long s = 0;
	long long total = 0;
	
	int k = 0;
	
	for (int i = 0; i < n; i++) {
		
		if (s + v[i] > t) 
			break;
		s += v[i];
		total = (total + s) % MOD;
		k++;
	}
	
	cout<<k<<" "<<total<<endl;
}
