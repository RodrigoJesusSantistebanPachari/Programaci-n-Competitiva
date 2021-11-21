#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//Entrada
    int n,k;
    cin>>n; cin>>k;
    unordered_map<int, int> diff;
	
	int temp;
	for(int i = 0; i < n; i++) {
        cin >> temp;
        diff[temp]++;
    }
	
	int proc = 0;
    for(int i = 0; i <= 999; i++)
        proc += diff[i];

    int mejor = proc;
    for(int i=1000; i<=100000; i++) {
        proc += diff[i];
        proc -= diff[i-1000];
        mejor = max(mejor, proc);
    }

     cout<<(mejor + k - 1)/k;
	
     return 0;
}
