#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//Entrada
	int n,k;
	int A,B;
    cin>>n; cin>>k;
    vector<int> stacks(n,0);
    vector<int> aux(n,0);
    for(int i=0; i<k; i++){
    	cin>>A; cin>>B;
    	stacks[A-1]++;
    	stacks[B]--;
	}
	aux[0] = stacks[0];
	for(int i=1; i<n; i++)
		aux[i] = aux[i-1]+stacks[i];
    sort(aux.begin(), aux.end());
    
    //Mediana
    if(n%2!=0)
    	cout<<aux[aux.size()/2];
    else
    	cout<<(aux[aux.size()/2]+aux[aux.size()/2-1])/2.0;

	return 0;
}
