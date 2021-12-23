#include<bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
 
#define INF 999999
int sa[INF], pos[INF], tmp[INF], lcp[INF];
int gap, N;
string S;
 
bool comp(long long x, long long y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void suffix() {
    for (long long i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (long long i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (long long i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        long long j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

pair<long long,long long> seg[INF*10];
long long mark[INF*10];
 
void push(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}
 
void update(long long v, long long a, long long b, long long k, long long x, long long y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    long long h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].F += h*v;
    long long d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}
int assign(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) 
		return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1; 
        return seg[k].F;
    }
    push(k); 
    long long d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;
 
}
int sum(long long a, long long  b, long long  k, long long  x, long long  y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    push(k); 
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    int d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}


int main(){

    
    cin>>S; N = S.size();
    suffix();
    build_lcp();
    long long k; cin>>k;

    k = N*(N+1)/2 - k + 1; //pos from last
    long long K = 1<<(long long) ceil(log2(N+1));
    long long cur = 0;
    for (long long i = N-1; i >= 0; i--) {
        update(1, 1, N-sa[i], 1, 0, K-1);
        long long prev = (i ? lcp[i-1] : 0);
        long long l = prev+1, r = N-sa[i];
        long long ans = -1;
        while (l <= r) {
            long long m = l + (r-l)/2;
            if (cur + sum(m, N-sa[i], 1, 0, K-1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) {
            return cout << S.substr(sa[i], ans), 0;
        }
        cur += sum(prev+1, N-sa[i], 1, 0, K-1);
        assign(0, prev+1, N-sa[i], 1, 0, K-1);
    }
}
