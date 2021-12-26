#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

#define INF 99999

string mul(string pow, int n);

void f1(vector<string>& S, int max) {
	string pow = "1";
	for (int i = 0; i < max; pow = mul(pow, 3), ++i){
		S.push_back(pow);
	}
}

void caso(unsigned long long n) {
	unsigned long long on = n;
	cout << "{ ";
	long long index = 0;
	while (n > 0) {
		if (n % 2 == 1) {
			cout << arr[index];
			if (n > 2) cout << ", ";
		}
		n /= 2;
		++index;
	}

	if (on != 0)
		cout << ' ';
	cout << "}\n";
}

int main(){
	
	f1(arr, 3000);
	unsigned long long n;
	
	cin >> n;
	do{
		caso(n - 1);
		cin >> n;
	}while (n != 0);
	return 0;
}

string mul(string pow, int n) {
	int x = 0;
	string rstring = "";
	for (int i = pow.length() - 1; i >= 0; --i) {
		x += n * (int)(pow.at(i) - '0');
		rstring = to_string(x % 10) + rstring;
		x /= 10;
	}
	if (x != 0) rstring = to_string(x % 10) + rstring;
	return rstring;
}
