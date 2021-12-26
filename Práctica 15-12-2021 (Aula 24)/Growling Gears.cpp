#include <bits/stdc++.h>

using namespace std;

#define INF 999999

void solve(int n, int t){
	cin >> t;
	
  	while (t--) {
	    cin >> n;
	    double a, b, c, t, mt = 0;
	    int answer = 1;
	    for (int i = 1; i <= n; i++) {
		    cin >> a >> b >> c;
		    t = b * b / (4 * a) + c;
		    if (t > mt){
				mt = t;
				answer = i;
			}
	    }
	    cout <<answer<<endl;
	}
}

int main() {
	
  int n;
  int t;
  
  solve(n,t);
  
  return 0;
  
}
