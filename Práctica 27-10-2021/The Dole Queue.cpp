#include <bits/stdc++.h>

using namespace std;

int main() {
	int N=-1, k=-1, m=-1;
	int a, b, c, i, e, f;
	vector<int> v(100,0);
	int cont;
	while(cin >> N >> k >> m && N) {
  	
  		cont++;
    	
		e = 0;
		f = N - 1;
		
    	for(i = 0; i < N; i++)
      		v[i] = i + 1;
      		
    	c = 0;
    	while(c < N) {
	      	i = k;
	      	while (i > 0){
	        	if(v[e] > 0) 
					i--;
	        		if(i == 0) 
						a = e;
	        	e = (e + 1) % N;
	      	}
	      	i = m;
	      	while(i > 0) {
	        	if(v[f] > 0) 
					i--;
	        		if(i == 0) 
						b = f;
	        	f = (f + N - 1) % N;
	      	}
	      	if(c > 0)
	        	cout <<",";
	      	if(a != b) {
	        	printf("%3d%3d", v[a], v[b]);
	        	c += 2;
	      	}
			else {
	        	printf("%3d", v[a]);
	        	c++;
	      	}
	    	v[a] = v[b] = 0;
    	}
    	cout <<endl;
	}
  
	return 0;
}
