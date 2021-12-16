#include <bits/stdc++.h>

using namespace std;

int main(){
    double N,L,W;
    
    while(cin>>N>>L>>W){
        double _x,_r;
        
        vector<pair<double,double>> v;
        
        for(int i = 0; i < N; i++){
        	
        	cin>>_x>>_r;
            if(_r*_r < (W/2.0)*(W/2.0))
                continue;
            double dx;
			dx = sqrt(_r*_r - (W/2.0)*(W/2.0));
            v.push_back(make_pair(_x-dx,_x+dx));
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        double l = 0;
        int i = 0;
        while(l < L){
            double newR=l;
            for(; i < v.size(); i++){
                if(v[i].first > l)
                    break;
                if(v[i].second>newR)
                    newR = v[i].second;
            }
            if(newR==l)
                break;
            l = newR;
            cnt++;
        }
        if(l >= L)
            cout<<cnt<<endl;
        else
            puts("-1");
    }
    return 0;
}
