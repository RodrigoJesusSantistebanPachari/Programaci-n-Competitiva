#include <bits/stdc++.h>

using namespace std;

int getTotal(int aux[], int n){
    int total = aux[0];
    for(int i=0; i<n; i++)
        total += (aux[i]*(aux[i]-1))/2;
    return total;
}
    
int subarraysDivByK(vector<int>& arr, int k) {
    int aux[k];
    for(int i=0; i<k; i++){
        aux[i]=0;		
    }

	int sum=0;
    for(int n:arr){
        sum += ((n%k)+k)%k;
        aux[sum%k]+=1;
    }

    return getTotal(aux, k);

}

int main(){
    
    int n, k;
    cout<<"k: ";cin>>k;
    cout<<"n: ";cin>>n;
    vector<int> arr(n);
    //Input
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<subarraysDivByK(arr,k);
    

    return 0;
}
