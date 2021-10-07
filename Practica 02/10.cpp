#include <iostream>
#include <vector>

using namespace std;


void mezclarArreglos(vector<int> A, vector<int> &B){
    
    for(int i=0; i<A.size(); i++){
        int j;
        for(j=0; j<B.size(); j++){
            if(A[i]<B[j]){
                break;
            }
        }
        B.insert(B.begin()+j, A[i]);
    }
}

int main(){
    
    vector<int> A;
    A.push_back(1);
    A.push_back(6);
    A.push_back(8);
    A.push_back(9);
    A.push_back(10);
    A.push_back(12);
    vector<int> B;
    B.push_back(2);
    B.push_back(3);
    B.push_back(4);
    B.push_back(5);
    B.push_back(6);
    B.push_back(8);
    B.push_back(9);
    B.push_back(20);
    
    mezclarArreglos(A,B);
    
    //mostrar B
    for(int i:B){
        cout<<i<<" ";
    }
    
    return 0;
}