#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	
    if (asteroids.size() == 0 || asteroids.size() == 1)
          return asteroids;

    vector<int> resultado;
    for(int i=0; i<asteroids.size(); i++){
    	
    	if(resultado.empty())
    		resultado.push_back(asteroids[i]);
    	else{
    		if(resultado.back() < 0 || asteroids[i] > 0)
    			resultado.push_back(asteroids[i]);
			else if(resultado.back()+asteroids[i] < 0){
				resultado.erase(resultado.end()-1);
				i--;
			}
			else if(resultado.back()+asteroids[i]==0)
				resultado.erase(resultado.end()-1);
		}
    
	}
	

	return resultado;
}

int main(){
	
	int n;
	cout<<"n: ";cin>>n;

	vector<int> asteroids(n);

	for(int i=0; i<n; i++)
		cin>>asteroids[i];

	vector<int> result = asteroidCollision(asteroids);
	
	for(int n: result)
		cout<<n<<" ";
		
	return 0;
}
