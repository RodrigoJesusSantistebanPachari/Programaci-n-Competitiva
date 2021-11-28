#include <bits/stdc++.h>

#define INF 999999

using namespace std;

int RectangleCutting(int a, int b){

	int rectangulo[a+1][b+1];
	
	for(int i=0; i<=a; i++){
		for (int j=0; j<=b; j++) {
			
			//Diagonalización
			if (i == j) {
				rectangulo[i][j] = 0;
			}
				
	    	else{
	    		
	    		int k=1;
	        	rectangulo[i][j] = INF;
	        	
	        	for(k = 1; k<j; k++){
	        		rectangulo[i][j] = min(rectangulo[i][j], rectangulo[i][k] + rectangulo[i][j-k]+1);
				}
				
	        	for(k = 1; k<i; k++){
	          		rectangulo[i][j] = min(rectangulo[i][j], rectangulo[k][j] + rectangulo[i-k][j]+1);
				}
				
	      	}
	    }
	}
	return rectangulo[a][b];
}


int main() {
	
	int a;
	int b;
	cin>>a>>b;
	cout<<RectangleCutting(a,b);
	
}
