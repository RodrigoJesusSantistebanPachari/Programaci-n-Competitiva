#include <bits/stdc++.h>

using namespace std;

void reemplazar(vector<vector<int>> &image, int i, int j, int old_color, int new_color){
	if (i < 0 || i > image.size() - 1)
        return;
    if (j < 0 || j > image[0].size() - 1)
        return;
        
    if (image[i][j] != old_color)
        return;
    else{
    	image[i][j] = new_color;
    	reemplazar(image, i, j - 1, old_color, new_color);      
        reemplazar(image, i, j + 1, old_color, new_color);           
        reemplazar(image, i - 1, j, old_color, new_color);           
        reemplazar(image, i + 1, j, old_color, new_color);
	}
               
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if(oldColor != newColor){
    	reemplazar(image,sr,sc,oldColor,newColor);
	}
	return image;
}

int main(){
	
	int f,c;
	cout<<"f: "; cin>>f;
	cout<<"c: "; cin>>c;
	vector<vector<int>> image;
	
	for(int i=0; i<f; ++i){
		vector<int> aux(c);
		for(int j=0; j<c; j++){
			cin>>aux[j];
		}
		image.push_back(aux);
	}
	
	int sr, sc, newColor;
	cout<<"sr: "; cin>>sr;
	cout<<"sc: "; cin>>sc;
	cout<<"new color: ";cin>>newColor;
	
	vector<vector<int>> resultado = floodFill(image, sr, sc, newColor);
	
	for(int i=0; i<resultado.size(); ++i){
		for(int j=0; j<resultado[i].size(); j++){
			cout<<resultado[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
