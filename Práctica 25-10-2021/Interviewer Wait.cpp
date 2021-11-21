#include <bits/stdc++.h>

using namespace std;


int InterviewerWait(vector<int> &V){
	deque<int> d;
	for(int n:V)
		d.push_back(n);
	
	int cont=0;
	int i=0;
	int n=0;
	while(n!=-1){
		cont+=n;
		if(i%2==0){
			n=d.back();
			d.pop_back();
		}
		else{
			n=d.front();
			d.pop_front();
		}
		
		i++;
	}
	
	return cont;
			
	
}


int main(){
	
	int n;
	cin>>n;
	vector<int> interviews(n);
	for(int i=0; i<n; ++i){
		cin>>interviews[i];
	}
	
	
	cout<<InterviewerWait(interviews);
	
	return 0;
}
