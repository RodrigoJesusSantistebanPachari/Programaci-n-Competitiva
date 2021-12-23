#include <bits/stdc++.h>
using namespace std;

const int maxsize = 2000000;
vector<int> _suffix_arr,_pos;
int N,indx;
string S;

bool comp(int x, int y){
    if (_pos[x] != _pos[y])
        return _pos[x] < _pos[y];
    x+=indx;
    y+=indx;
    return (x<N &&y<N)?_pos[x]<_pos[y]:x>y;
}

void suffix_array(){
    for (int i = 0; i < N; i++){
        _suffix_arr.push_back(i);
        _pos.push_back(S[i]);
    }
    int tmp[maxsize];
    for (indx = 1;; indx <<= 1) {
        sort(_suffix_arr.begin(), _suffix_arr.end(), comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(_suffix_arr[i], _suffix_arr[i+1]);
        for (int i = 0; i < N; i++)
            _pos[_suffix_arr[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

int lcp(){
    int longest_prefix_size=0;
    vector<int> _lcp(N);
    for (int i=0,k=0; i<N;i++){
        if (_pos[i] != N-1){
            int j = _suffix_arr[_pos[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            _lcp[_pos[i]+1] = k;
            longest_prefix_size = max(longest_prefix_size,_lcp[_pos[i]+1]);
            if (k) k--;
        }
    }
    return longest_prefix_size;
}

int Dvaput(){
    suffix_array();
    return lcp();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>S;
    cout<<Dvaput();
    return 0;
}
