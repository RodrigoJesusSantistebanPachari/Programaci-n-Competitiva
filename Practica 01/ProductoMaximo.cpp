//Alumno: Rodrigo Jesus Santisteban Pachari

#include <iostream>

using namespace std;

int productoMaximo(int arr[], int n){
    int mayor = arr[0], segundo_mayor = -999999;
    for(int i=0; i<n; i++){
      if(mayor<arr[i]){
        segundo_mayor = mayor;
        mayor = arr[i];
      }
      if(segundo_mayor<arr[i] && arr[i]!=mayor){
        segundo_mayor = arr[i];
      }
    }

    return  mayor*segundo_mayor;
}

int main() {

  int n;
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];
  
  cout<<productoMaximo(arr, n);

  return 0;
}