#include <iostream>

using namespace std;

long long int fibonacciIterativo(long long int n){
    long long int actual=1, siguiente=1, tmp=0;
    for(long long int i=1; i<n; i++){
        tmp = actual;
        actual = siguiente;
        siguiente = siguiente + tmp;
    }
    return actual;
}


int main(){
    
    cout<<"9no: "<<fibonacciIterativo(9)<<endl;
    cout<<"14avo: "<<fibonacciIterativo(14)<<endl;
    cout<<"58avo: "<<fibonacciIterativo(58)<<endl;

    return 0;
}

