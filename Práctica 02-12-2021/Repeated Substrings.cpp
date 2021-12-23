#include <bits/stdc++.h>

#define INF 9999999;

using namespace std;

int main(){
	
    long long t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        s += " ";
        int n = s.length();
        vector<int> sa(n), c(n);
        vector<pair<int, int>> v(n);
        
        auto count_sort = [&](){
        	
            vector<int> cnt(n), sa_new(n);
            for(auto x: c)
                cnt[x]++;
            vector<int> pos(n);
            
            for(int i = 1; i < n; i++){
                pos[i] = pos[i-1] + cnt[i-1];
            }
            
            for(auto x: sa){
                int i = c[x];
                sa_new[pos[i]] = x;
                pos[i]++;
            }
            sa = sa_new;
        };
        
        for(int i = 0; i < n; i++){
            v[i] = {s[i] - '0', i};
		}
		
        sort(v.begin(), v.end());
        
        for(int i = 0; i < n; i++){
            sa[i] = v[i].second;
		}
		
        c[sa[0]] = 0;
        for(int i = 1; i < n; i++){
            c[sa[i]] = c[sa[i-1]] + !(v[i].first == v[i-1].first);
        }
        
        int k = 0;
        while(n > (1LL<<k)){
            for(int i = 0; i < n; i++){
                sa[i] = (sa[i] - (1<<k) + n) % n;
            }
            count_sort();
            vector<int> c_new(n);
            
            c_new[sa[0]] = 0;
            for(int i = 1; i < n; i++){
                pair<int, int> prev = {c[sa[i-1]], c[(sa[i-1] + (1<<k)) % n]};
                pair<int, int> now = {c[sa[i]], c[(sa[i] + (1<<k)) % n]};
                if(now == prev)
                    c_new[sa[i]] = c_new[sa[i-1]];
                else
                    c_new[sa[i]] = c_new[sa[i-1]] + 1;
            }
            c = c_new;
            k++;
        }
        
        k = 0;
        vector<int> lcp(n);
        for(int i = 0; i < n-1; i++){
            int pi = c[i];
            int j = sa[pi-1];
            while(s[i+k] == s[j+k])
                k++;
            lcp[pi] = k;
            k = max(k-1, 0);
        }
        
        long long  ans = 0;
        for(int i = 1; i < n; i++){
            if(lcp[i] > lcp[i-1]){
                ans += lcp[i] - lcp[i-1];
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
