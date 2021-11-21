#include <bits/stdc++.h>

using namespace std;

void pairing_socks(vector<int> arr){
	int movimientos = 0;
	vector<int> aux;
    while(!arr.empty()) {
    	
        movimientos++;

        if(aux.empty()) {
            aux.push_back(arr.back());
            arr.pop_back();
            continue;
        }

        if(arr.back() == aux.back()) {
            arr.pop_back();
            aux.pop_back();
            continue;
        }

        aux.push_back(arr.back());
        arr.pop_back();
    }

    if(aux.empty())
        cout<<movimientos<<endl;
    else
        cout<<"impossible"<< endl;
}

int main(){
	
	//Entrada
	int s;
    cin>>s;
    vector<int> arr (2*s);
    
    for(int i=0; i<2*s; i++)
    	cin>>arr[i];
    
    pairing_socks(arr);
	return 0;
}
