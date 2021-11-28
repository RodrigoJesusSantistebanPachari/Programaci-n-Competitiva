#include <bits/stdc++.h>

#define EMPTY -99999
#define INF 999

using namespace std;

int mem[INF][INF];
string input;

void reset(){
	for(int i=0; i<INF; i++){
		for(int j=0; j<INF; j++)
			mem[i][j] = EMPTY;
	}
}

int stackConstruction(int idx1, int idx2) {
    if (idx1 > idx2) {
    	return 0;
	}
	else{
		if (mem[idx1][idx2] == EMPTY) {
	        mem[idx1][idx2] = stackConstruction(idx1, idx2-1) + 1;
			
			int i=idx1;
			
			while(i<idx2){
				
				if (input[i] == input[idx2]){
					
					int aux = stackConstruction(idx1,i) + stackConstruction(i+1,idx2-1);
					
	                mem[idx1][idx2] = min(mem[idx1][idx2], aux);
	            }
				i++;	
			}
    	}

    	return mem[idx1][idx2];
	}
    
}

int main() {
    int n;
    cin >> n;
    int res;
    
	cin.ignore();
    
    for(int i=0; i<n; i++){
		reset();
		getline(cin,input);
		int aux = stackConstruction(0, input.size()-1);
        res = aux*2 + input.size();
    	cout<<res<<endl;		
	}
    return 0;
}
