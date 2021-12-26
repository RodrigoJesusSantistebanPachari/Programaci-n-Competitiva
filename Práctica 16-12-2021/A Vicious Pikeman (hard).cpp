#include <bits/stdc++.h>

using namespace std;

#define INF 999999

void solve(long long N,long long  T,long long  A,long long  B,long long  C,long long  t0){
	
	vector<long long> arr(C + 1, -1);
	
	//Inicio
	arr[t0] = 0;
	long long aux1 = t0, aux2 = 0;
	int i=1;
	
	
	while(true){
		
		aux1 = (A * aux1 + B) % C + 1;
		if (arr[aux1] == -1) 
			arr[aux1] = i;
		else {
			aux2 = aux1;
			break;
		}
		i++;
	}
	
	long long looplength = i - arr[aux2];

	vector<long long> countof(C + 1, 0);
	long long lef = N;
	for (aux1 = t0; aux1 != aux2 && lef > 0; aux1 = (A * aux1 + B) % C + 1) {
		countof[aux1]++;
		lef--;
	}

	for (i = 0, aux1 = aux2; i < looplength; ++i, aux1 = (A * aux1 + B) % C + 1) {
		countof[aux1] += lef / looplength;
		if (i < lef % looplength) 
			countof[aux1]++;
	}

	long long pr = 0, tm = 0, Tleft = T, Tused = 0, MOD = 1e9+7;
	for (int j = 1; j <= C; ++j) {
		if (countof[j] == 0) 
			continue;
		if (Tleft < j) 
			break;
		long long s = min(countof[j], Tleft / j);
		pr += s;
		Tleft -= j * s;
		long long sM = s % MOD;
		tm = (tm + ((sM * (Tused % MOD)) % MOD)) % MOD;
		if (sM % 2 == 0)
			tm = (tm + ((((sM / 2 * (sM + 1)) % MOD) * j) % MOD)) % MOD;
		else
			tm = (tm + (((((sM + 1) / 2 * sM) % MOD) * j) % MOD)) % MOD;
		Tused += j * s;
	}

	cout << pr << " " << (tm % MOD) << endl;
}

int main() {

	long long N, T, A, B, C, t0;
	cin >> N >> T >> A >> B >> C >> t0;

	solve(N, T, A, B, C, t0);

	return 0;
}
