#include <bits/stdc++.h>

using namespace std;

void interviewQueue(vector<int> interviews){
	
	bool flag = true;
	vector<vector<int>> vistas;
	
	while(flag){
		flag = false;
		vector<int> pos;
		vector<int> eliminados;
		for(int i=0; i<interviews.size(); i++){
			if(i==0){
				if(interviews[i]<interviews[i+1]){
					pos.push_back(i);
					eliminados.push_back(interviews[i]);
					flag = true;
				}
			}
			else if(i==interviews.size()-1){
				if(interviews[i]<interviews[i-1]){
					pos.push_back(i);
					eliminados.push_back(interviews[i]);
					flag = true;
				}
			}
			else{
				if(interviews[i]<interviews[i-1] || interviews[i]<interviews[i+1]){
					pos.push_back(i);
					eliminados.push_back(interviews[i]);
					flag = true;
				}
			}
		}
		
		vistas.push_back(eliminados);
		//Eliminar
		for(int i=0; i<pos.size(); i++){
			interviews.erase(interviews.begin() + pos[i]-i);
		}
		
	}
	
	
	cout<<vistas.size()-1<<endl;	//minutos
	for(int i=0; i<vistas.size(); i++){
		for(int j=0; j<vistas[i].size(); j++){
			cout<<vistas[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0; i<interviews.size(); i++)
		cout<<interviews[i]<<" ";
}

int main(){
	
	int n;
	cin>>n;
	vector<int> interviews(n);
	for(int i=0; i<n; ++i)
		cin>>interviews[i];
	
	
	interviewQueue(interviews);
	
	return 0;
}
