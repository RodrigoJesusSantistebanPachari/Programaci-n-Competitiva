#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int p; cin>>p;
	while(p--){
		int n;
		cin>>n;
		vector<int> S(n);
		for(int i=0; i<n; i++)
			cin>>S[i];
		sort(S.begin(), S.end());
		
		for(int k=0; k<n-1; k++)
			cout<<S[k]<<" ";
		cout<<S[n-1];
		cout<<endl;
	}
	
	
	return 0;
}
