#include <math.h>

//Fibonacci Recursivo
long long int fibonacciRecursivo(long long int n){
  if(n<=1)
    return n;
  else{
    return fibonacciRecursivo(n-1)+fibonacciRecursivo(n-2);
  }
}

//Fibonacci Iterativo
long long int fibonacciIterativo(long long int n){
  long long int actual=1, siguiente=1, tmp=0;
  for(long long int i=1; i<n; i++){
    tmp = actual;
    actual = siguiente;
    siguiente = siguiente + tmp;
  }
  return actual;
}

//Fibonacci Double
double fibonacciDouble(double n){
  double actual=1, siguiente=1, tmp=0;
  for(int i=2; i<=n; i++){
    tmp = actual;
    actual = siguiente;
    siguiente = siguiente + tmp;
  }
  return actual;
}

/* Fibonacci Python

def fibonacci_iterativo(posicion):
    temporal = 0
    actual = 1
    siguiente = 1
    for x in range(posicion):
        temporal = actual
        actual = siguiente
        siguiente = siguiente + temporal
    return temporal

*/

//ArtiméticaModular
//Calculamos Fibonacci módulo M
int fibonacciModular(long long int n, int mod){
  long long int actual=1, siguiente=1, tmp=0;

  for(long long int i=1; i<n; i++){
    //Acá agregamos la teoría de aritmética ArtiméticaModular
    if(actual >= mod || siguiente >= mod){
      actual = actual%mod;
      siguiente = siguiente%mod;
    }

    tmp = actual;
    actual = siguiente;
    siguiente = siguiente + tmp;
    
  }
  return actual;
}

//Obtiene la diagonal de una matriz 2x2 y devuelve un arreglo con la diagonal
double* obtenerDiagonal(double M[2][2]){
  double* v = new double[2];
  v[0] = M[0][0];
  v[1] = M[1][1];
  return v;
}

//Forma matricial
double fibonacciMatricial(long int n){
  double lambdax = (1+sqrt(5))/2;
  double lambday = (1-sqrt(5))/2;
  //Matriz con las diagonales con lambda
  double M[2][2] = {{lambdax,0},
                  {0,-lambday}};
  double* v = new double[2];
  v = obtenerDiagonal(M);
  
  //Multiplicamos el vector con 1/sqrt(5) y elevamos los lamda a la n
  double fibonacci = 1/sqrt(5)*pow(v[0],n)+1/sqrt(5)*pow(v[1],n);

  return fibonacci;
}
