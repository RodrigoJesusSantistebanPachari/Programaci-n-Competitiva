#include <iostream>
#include <ctype.h>

using namespace std;

void swap(char* a, char* b){  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int Particion (string &arr, int low, int high)  {  
    char pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++){  
        if (arr[j] < pivot){  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void QuickSort(string &arr, int low, int high){  
    if (low < high){  
        int pi = Particion(arr, low, high);  
        QuickSort(arr, low, pi - 1);  
        QuickSort(arr, pi + 1, high);  
    }  
}  


void convertirMayusculas(string &word){
  for (int i = 0; i < word.length(); i++){
    word[i] = toupper(word[i]);
  }
}

bool sonAnagramas(string w1, string w2){
  convertirMayusculas(w1);
  convertirMayusculas(w2);
  QuickSort(w1,0,w1.size()-1);
  QuickSort(w2,0,w2.size()-1);
  cout<<w1<<" "<<w2<<endl;
  if(w1==w2)
    return true;
  else
    return false;
}

int main() {

  string w1, w2;
  getline(cin, w1);
  getline(cin, w2);
  if (sonAnagramas(w1,w2))
    cout<<"Son anagramas";
  else
    cout<<"No son anagramas";

  return 0;

}