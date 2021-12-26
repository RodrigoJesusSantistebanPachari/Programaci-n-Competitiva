#include<bits/stdc++.h>

#define INF 9999
#define ll long long
#define v vector
#define FOR(i,A,B,C) for(int i=A; i<B; i+=C)
#define FOR_bitOR(i,A,B,C) for(int i=A; i<B; i|=C)
#define FOR_bitAND_min(i,A,B,C) for(int i=A; i>B; i&=C)

using namespace std;

v<ll> arr1(INF, 0);
v<ll> arr2(INF, 0);
v<ll> arr3(INF, 0);

int main() {
	
	ll n; cin>>n;
	
	arr1.resize(n+1);
	arr2.resize(n+1);
	arr3.resize(n+1);

	ll sumAux = 0;

	FOR(i,0,n,1){
			
    	long long num;
    	cin>>num;
    	
    	long long parcial = 0;
		FOR_bitAND_min(i,num+1,0,i-1){
			parcial = parcial + arr1[i-1];
		}
    	
    	ll cont1 = 0;
    	ll cont2 = 0;
    	
		FOR_bitAND_min(i,arr1.size(),0,i-1){
			cont1 = cont1+arr1[i-1];
		}
		
		cont1 -= parcial;
		
		parcial = 0;
		FOR_bitAND_min(i,num+1,0,i-1){
			parcial = parcial + arr2[i-1];
		}
		
		FOR_bitAND_min(i,arr2.size(),0,i-1){
			cont2 = cont2 + arr2[i-1];
		}
		cont2 -=parcial;
	
		FOR_bitOR(j, num, arr1.size(), j+1){
    		arr1[j] += 1;
		}
		
		FOR_bitOR(j, num, arr2.size(), j+1){
    		arr2[j] += cont1;
		}
		
		FOR_bitOR(j, num, arr3.size(), j+1){
    		arr3[j] += cont2;
		}
  	}
	
	ll final = 0;
	FOR_bitAND_min(i,arr3.size(),0,i-1){
		final = final + arr3[i-1];
	}

  	cout<<final<<endl;
  	
  	return 0;
}
