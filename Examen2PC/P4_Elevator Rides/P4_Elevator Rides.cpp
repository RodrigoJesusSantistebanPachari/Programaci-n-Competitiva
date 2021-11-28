//https://cses.fi/problemset/task/1653/

#include<bits/stdc++.h>

#define INF 9999

using namespace std;

int ElevatorRides(int n, int x, vector<int>& v){
	
	pair<int, int> resp[1<<n];
    resp[0] = {1,0};
    
    int idx = (1<<n);
       
    for(int i=1;i<idx;i++){
    	
    	resp[i].first = n+1;
    	resp[i].second = 0;
        
		for(int j=0;j<n;j++){
			
			int idx2 = (1<<j);
			
            if(i & idx2){     
			  
				pair<int,int> aux= resp[i^idx2];
				
                if(aux.second+v[j] <= x)
                    aux.second += v[j];
                    
                else{
                    aux.first++;
                    aux.second=v[j];
                }
                
            	resp[i]=min(resp[i],aux);
            }
              
        }
    }
    
    
    return resp[idx-1].first;
}

int main(){
	
	int n,x;

    cin>>n>>x;
    vector<int> vector(n);
    
    for(int i=0;i<n;i++)
    	cin>>vector[i];
    
	cout<<ElevatorRides(n,x,vector)<<endl;
}
