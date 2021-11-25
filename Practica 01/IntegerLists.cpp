#include <bits/stdc++.h>

using namespace std;


void IntegerLists(deque<int> &lista, string bapc){
    int cont = 0;
    for(int i=0; i<bapc.size(); i++){
        if(bapc[i] == 'R')
            cont++;
            
        else{
            if(lista.size()==0){
                cout<<"error"<<endl;
                return;
            }
            else if(cont%2==0)
                lista.pop_front();  
            else
                lista.pop_back();
        }
    }
    
    if(cont%2==0){
        cout<<"[";
        while(lista.size() != 1){
            cout<<lista.front()<<",";
            lista.pop_front();
        }
        cout<<lista.front()<<"]"<<endl;
    }
    else{
        cout<<"[";
        while(lista.size() != 1){
            cout<<lista.back()<<",";
            lista.pop_back();
        }
        cout<<lista.back()<<"]"<<endl;
    }
    
}


int main(){
    
    int n, size, pos1, elem;
    cin>>n;
    string bapc;
    string list;
    
    deque<int> camino;
    
    for(int i=0; i<n; i++){
        
        //Cadena
        cin>>bapc;
        
        cin>>size;
        
        
        cin>>list;
        list.erase(list.begin());
        for(int j=0; j<size-1; j++){
            pos1 = list.find_first_of(",");
            elem = stoi(list.substr(0, pos1));
            list.erase(0, pos1+1);
            camino.push_back(elem);
        }
        if(size!=0){
            elem = stoi(list.substr(0, list.find_first_of("]")));
            camino.push_back(elem);
        }
        IntegerLists(camino,bapc);
        
        camino.clear();
    }
    
    
    return 0;
}
