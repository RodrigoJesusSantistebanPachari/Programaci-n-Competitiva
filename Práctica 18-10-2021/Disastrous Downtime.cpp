#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//Entrada
	int n,k;
	int A;
    cin>>n; cin>>k;
    map<int, int> diff;

    for(int i=0; i<n; i++){
    	cin>>A;
    	auto busq = diff.find(A);
    	if(busq == diff.end())
    		diff.insert({A, 1});
    	else
    		diff[A]++;
    	busq = diff.find(A+1000);
    	if(busq == diff.end())
    		diff[A+1000]--;
    	else
    		diff.insert({A+1000, -1});
	}
	
	vector<int> acc(diff.size());
	
	acc[0] = diff.begin()->second;
	
	auto it = diff.cbegin();
	it++;
	for(int i=1; i<diff.size(); i++){
		acc[i] = acc[i-1]+ (it->second);
		it++;
	}
	
	//for(int n:acc)
	//	cout<<n<<" ";
		
	cout<<endl;
	int max = *max_element(acc.begin(), acc.end());
	float resultado = max/(k*1.0);
	
	if(resultado-trunc(resultado) > 0)
		cout<<trunc(resultado)+1;
	else
		cout<<trunc(resultado);

	return 0;
}
