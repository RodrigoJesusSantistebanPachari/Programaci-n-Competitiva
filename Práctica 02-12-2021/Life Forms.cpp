#include <bits/stdc++.h>
using namespace std;

const int maxsize = 100500;
vector<int> _suffix_arr,_pos,_lcp,_map_string_color;
int N,indx;
string S;

bool comp(int a, int b){
    if (_pos[a] != _pos[b])
        return _pos[a] < _pos[b];
    a+=indx;
    b+=indx;
    return (a<N &&b<N)?_pos[a]<_pos[b]:a>b;
}

vector<int> suffix_array(){
    N = S.size();
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
    return _suffix_arr;
}

vector<int> lcp(){
    vector<int>__lcp(N);
    for (int i=0,k=0; i<N;i++){
        if (_pos[i] != N-1){
            int j = _suffix_arr[_pos[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            __lcp[_pos[i]+1] = k;
            if (k) k--;
        }
    }
    _lcp=__lcp;
    return __lcp;
}

int n_strings;

bool LCS_size_l(int l,bool print){
    bool counted[n_strings]; 
    int count;
    for (int i = 1; i < N; ++i) {
        if (_lcp[i] >= l) {
            for(int _i=0;_i<n_strings;_i++) counted[_i] = false;
            count = 1;
            counted[_map_string_color[_suffix_arr[i-1]]] = true;
            int j = i;
            while (j < N && _lcp[j] >= l) {
                if (_map_string_color[_suffix_arr[j]] != _map_string_color[_suffix_arr[j]+l-1]){
                    break;
                }
                if (!counted[_map_string_color[_suffix_arr[j]]]) {
                    counted[_map_string_color[_suffix_arr[j]]] = true;
                    ++count;
                }
                ++j;
            }
            if (count > n_strings/2) {
                if(print){
                    cout<<S[_suffix_arr[i]];
                    for (int k = 1; k < l; ++k)
                        cout<<S[_suffix_arr[i]+k];
                    cout<<endl;
                }
                else return true;
            }
            i = j-1;
        }
    }    
    return false;
}

int LCS(){
    vector<string> entrada;
    int min_string_size=maxsize;
    S="";
    
    for(int i=0;i<n_strings;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++){
            S+=temp[j];
            _map_string_color.push_back(i);
        }
        if(temp.size()<min_string_size) 
            min_string_size=temp.size();
        S+=123+i;
        _map_string_color.push_back(0);
    }
    S.pop_back();
    _map_string_color.pop_back();
    suffix_array();
    lcp(); 
    
    int min=1,_ans=-1;
    while(min_string_size >= min){
        int  mid = (min_string_size-min)/2 + min;
        if(LCS_size_l(mid,false)){
            min=mid+1;
            _ans=max(_ans,mid);
        }
        else
            min_string_size = mid - 1;
    }
    if(_ans==-1){
        cout<<"?";
        return _ans;
    } 
    LCS_size_l(_ans,true);
    return _ans;
}


int main(){

    n_strings=-1;
    
    while(true){
        cin>>n_strings;
        if(n_strings==0) return 0;
        LCS(); 
        cout<<"\n";
        
        //clear buffer
        S.clear();
        N = 0;
        _suffix_arr.clear();
        _pos.clear();
        _lcp.clear();
        _map_string_color.clear();
    }  
    
    return 0;
}
