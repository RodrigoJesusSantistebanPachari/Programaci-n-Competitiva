#include <iostream>
#include <math.h>
#include "Fibonacci.h"

using namespace std;


int main(){
  
  int limite = pow(2,30);
  int modulo = pow(2,20);
  
  cout<<"Fibonacci(2^30)%2^20: " <<fibonacciModular(limite, modulo)<<endl;
  

  return 0;
}