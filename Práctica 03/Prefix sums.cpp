#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, cont=0;
    cout<<"n: ";cin>>n;
    int arr[n];
    //Input
    for(int i=0; i<n; i++){
        cout<<"a_"<<i<<": ";cin>>arr[i];
    }
    
    //Output
    cout<<endl<<"p_0: "<<cont<<endl;
    for(int i=0; i<n; i++){
    	cont+=arr[i];
        cout<<"p_"<<i+1<<": "<<cont<<endl;
    }


    return 0;
}
