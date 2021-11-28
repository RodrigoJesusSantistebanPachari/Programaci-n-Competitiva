//https://www.beecrowd.com.br/judge/en/problems/view/2792


#include <bits/stdc++.h>
#define INF 999999
using namespace std;

int auxF(int a, vector<int>& vec){
    int sum = 0;
    while(a > 0){
        sum += vec[a];
        a -= (a & (-a));
    }
    return sum;
}

void actualizar(int a, int v,vector<int>& vec ){
    while(a < INF){
        vec[a] += v;
        a += (a & (-a));
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> vec(INF,0);
    int aux;
    int res;
    for(int i = 1; i <= n; i++){
        cin>>aux;
        res = aux-auxF(aux,vec);
        cout<<res<< (i == n ? "\n" : " ");
        actualizar(aux, 1, vec);
    }

    return 0;
}
