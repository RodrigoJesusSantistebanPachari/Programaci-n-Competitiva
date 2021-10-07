#include <bits/stdc++.h>

using namespace std;

template<typename T>
class priority_queue_improved : public priority_queue<T, vector<T>>{
  	public:
      	bool remove(const T& value) {
    		auto it = find(this->c.begin(), this->c.end(), value);
    		if (it != this->c.end()) {
            	this->c.erase(it);
            	make_heap(this->c.begin(), this->c.end(), this->comp);
            	return true;
       		}
       		else {
        		return false;
    		}
		}
};

vector<int> getMaximunSum(vector<int> nums, int k){
	
	int n = nums.size();
	vector<int> salida;
	priority_queue_improved<int> cola_prioridad;
	
	for(int i=0; i<k; i++){
		cola_prioridad.push(nums[i]);
	}
	
	int cont=0;
	for(int i=k; i<n; i++){
	
		salida.push_back(cola_prioridad.top());
		cola_prioridad.remove(nums[cont]);
		cola_prioridad.push(nums[i]);
		cont++;
		
	}
	
	salida.push_back(cola_prioridad.top());
	
	return salida;
}




//Complejidad: O(nlog(n))
int main(){
    
    //Entrada
    int n, S;
    cout<<"n: ";cin>>n; 
	cout<<"S: ";cin>>S;
    vector<int> arr(n);
    
    //Leyendo input
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    
    //Output
    vector<int> salida = getMaximunSum(arr, S);
    for(int i=0; i<salida.size(); i++)
        cout<<salida[i]<<" ";


    return 0;
}
