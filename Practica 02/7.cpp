#include <iostream>

using namespace std;

int main(){
    
    int n = 8;
    
    cout<<((n & (n-1)) == 0);
    
    
    //Lo que hace es un and entre un numero n y su numero menor n-1, transformados a binario.
    //Por ejemplo, si fuese 11 el número, se comprueban
    //1011 <- 11
    //1010 <- 10
    //Una vez comprobados, se verificará si son diferentes de 0
    //Por lo tanto se usa para verificar si un número es potencia de 2 o no
    return 0;
}

