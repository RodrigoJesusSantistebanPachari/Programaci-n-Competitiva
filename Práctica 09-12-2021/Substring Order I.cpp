#include<bits/stdc++.h>
using namespace std;

#define INF 9999999

long long sa[INF], pos[INF], tmp[INF], lcp[INF];
long long  gap, N;
string S;
 
bool comp(long long  x, long long  y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void sufijos() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void construirLCP() {
    for (int i = 0, k = 0; i < N; i++) 
		if (pos[i] != N-1) {
        long long j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k)
			k--;
    }
}
 
int  main(){
	
    
    cin>>S; 
	N = S.size();
    
	sufijos();
	
    construirLCP();
    
    long long  k; 
	cin>>k;
    
	long long  prev = 0;
    long long  act = 0;
    
    
    for (int i = 0; i < N; i++) {
        if (act + (N-sa[i]) - prev >= k) {
            long long  j = prev;
            string ans = S.substr(sa[i], j);
            while (act < k) {
                ans += S[sa[i]+j];
                act++;
                j++;
            }
            cout<<ans;
            return 0;
        }
        act += (N-sa[i]) - prev;
        prev = lcp[i];
    }
}
