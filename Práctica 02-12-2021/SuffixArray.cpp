#include <bits/stdc++.h>

using namespace std;

vector<pair<string,int>> getSufijo(string cad){
	vector<pair<string,int>> sufijos;
	int i=0;
	while(cad.size() != 0){						//n
		sufijos.push_back(make_pair(cad,i));
		cad.erase(cad.begin());
		i++;
	}
	
	sort(sufijos.begin(), sufijos.end());	//n*log(n)
	
	//O(n*log(n))
	
	return sufijos;
}

int main(){
	
	string cad;
	cin>>cad;
	
	vector<pair<string,int>> sufijos = getSufijo(cad);
	
	for(int i=0; i<sufijos.size(); i++){
		cout<<sufijos[i].second<<" "<<sufijos[i].first<<endl;
	}
	
	return 0;
}
