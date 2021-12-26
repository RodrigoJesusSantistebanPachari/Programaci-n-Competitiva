#include<bits/stdc++.h>

#define INF 9999
#define FOR(i,A,B,C) for(int i=A; i<B; i+=C)

using namespace std;

//O(n)
int calcular(vector<int> arr) {
	
	int n = arr.size();
	
	FOR(i,0,n+1,2)
        if (arr[i] != arr[i + 1])
            return arr[i];
    
    if (arr[n - 1] == arr[n - 2])
        return 0;

	else
		return arr[n - 1];

}

int main() {
    
    int n;
	vector<int> arr(INF);
    int T; cin>>T;
    
    FOR(i,1,T+1,1){
        
	    cin >> n;
	    arr.resize(n);
	    
	    FOR(j,0,n,1){
	        cin>>arr[j];
	    }
	    
	    //O(n*log(n))
	    sort(arr.begin(), arr.end());
	    
	    //O(n)
	    cout << "Case #" <<i<<": "<<calcular(arr)<<endl;
    }

    return 0;
}
