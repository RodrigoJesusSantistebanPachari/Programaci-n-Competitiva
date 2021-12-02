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

vector<int> getLCP(string txt, vector<pair<string,int>> sufijos){
	
	int n = sufijos.size();
	vector<int> LCP (n,0);
	
	vector<int> aux(n,0);
	
	for (int i=0; i < n; i++)
        aux[sufijos[i].second] = i;
        
    int k = 0;
 
    for (int i=0; i<n; i++){
  
        if (aux[i] == n-1){
            k = 0;
            continue;
        }
 
        int j = sufijos[aux[i]+1].second;
 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
 
        LCP[aux[i]] = k;
 
        if (k>0)
            k--;
    }
 
    return LCP;
}


int main(){
	
	string cad;
	cin>>cad;
	
	vector<pair<string,int>> sufijos = getSufijo(cad);
	
	cout<<"Sufix Array:"<<endl;
	for(int i=0; i<sufijos.size(); i++){
		cout<<sufijos[i].second<<" "<<sufijos[i].first<<endl;
	}
	
	vector<int> LCP = getLCP(cad, sufijos);
	
	cout<<"LCP Array:"<<endl;
	for(int n:LCP){
		cout<<n<<endl;
	}
	
	
	return 0;
}
