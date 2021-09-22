#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, k, num, cont = 0;
    cin>>n; cin>>k;
    for(int i=0; i<n; i++){
        cin>>num;
        if(num%k==0)
            cont++;
    }
    
    cout<<cont;

    return 0;
}

