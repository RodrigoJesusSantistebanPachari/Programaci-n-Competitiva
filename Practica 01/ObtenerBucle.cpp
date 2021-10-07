//Estudiante: Rodrigo Jesus Santisteban Pachari

#include <iostream>
#include <vector>

using namespace std;

vector<int> obtenerBucle(int arr[], int n){

  vector<int> salida;
  int k, l;

  bool flag = false;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i] == arr[j] && i!=j){
        cout<<i<<" "<<j<<endl;
        l = i;
        k=j;
        flag = true;
        break;
      }
    }
    if(flag)
      break;
  }

    //"Lim 1 = " l
    //"Lim 2 = " k 

    int lim = 0;
    for(int i=0; i<=k-l-1; i++)
      salida.push_back(arr[i+l]);

    return salida;
}

int main() {

  int n;
  cout<<"Size: ";
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];

  vector<int> salida = obtenerBucle(arr, n);

  for(int i=0; i<salida.size(); i++)
    cout<<salida[i]<<" ";

  return 0;
}