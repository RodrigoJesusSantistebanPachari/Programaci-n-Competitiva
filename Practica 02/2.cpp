#include <iostream>
#include <list>

using namespace std;

void eliminarDuplicados (list<int> &lista){
    // Primero ordenamos la secuencia
    lista.sort();  
    
    // Despues eliminamos los duplicados
    lista.unique();
}

int main(){
    
    list<int> lista;
    lista.push_back(3);
    lista.push_back(5);
    lista.push_back(1);
    lista.push_back(5);
    lista.push_back(0);
    lista.push_back(3);
    
    
    for (int n : lista) {
        std::cout << n << ", ";
    }
    
    eliminarDuplicados(lista);
    cout<<endl<<"Eliminando duplicados"<<endl;
 
    for (int n : lista) {
        std::cout << n << ", ";
    }
    
    
    return 0;
}
