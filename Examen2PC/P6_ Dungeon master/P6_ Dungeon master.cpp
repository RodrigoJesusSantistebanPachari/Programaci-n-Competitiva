//https://open.kattis.com/problems/dungeon

#include <bits/stdc++.h>

#define INF 999999

using namespace std;

struct Punto {
    int l,r,c;

    Punto(int l1, int r1, int c1) : l(l1), r(r1), c(c1){
    	
	}

    Punto() : l(0), r(0), c(0){
	}
};

int busqueda_anchura(vector<vector<vector<int>>> dungeon, Punto punto, Punto e, int maxl, int maxr, int maxc);

void iniciar(int l,int r,int c){
	char car;
    Punto inicio, fin;

	int time;    

    while(l && r && c){

        vector<vector<vector<int>>> dungeon(l, vector<vector<int>>(r, vector<int>(c, -1)));

        scanf("%c", &car); 

        for(int ll = 0; ll < l; ll++){
            for(int rr = 0; rr < r; rr++){
                for(int cc = 0; cc < c; cc++){
                    scanf("%c", &car);
                    if(car == '#')
                        dungeon[ll][rr][cc] = -2;
                    if(car == 'S')
                        inicio = {.l = ll, .r = rr, .c = cc};
                    if(car == 'E')
                        fin = {.l = ll, .r = rr, .c = cc};
                }
                scanf("%c", &car);
            }
            scanf("%c", &car);
        }

        time = busqueda_anchura(dungeon, inicio, fin, l, r, c);

        if(time < 0)
            cout<<"Trapped!"<<endl;
        else
            cout<<"Escaped in "<<time<<" minute(s)."<<endl;

        scanf("%d %d %d", &l, &r, &c);
    }
}

bool entrada(int l, int r, int c, int maxl, int maxr, int maxc){
    return (l >= 0 
			&& l < maxl 
			&& r >= 0 
			&& r < maxr 
			&& c >= 0 
			&& c < maxc);
}

int busqueda_anchura(vector<vector<vector<int>>> dungeon, Punto punto, Punto e, int maxl, int maxr, int maxc){
    queue<Punto> cola;
    cola.push(punto);
    dungeon[punto.l][punto.r][punto.c] = 0;
	
	//La cola de puntos tiene que quedar vacía
    while(!cola.empty()){
    	
        Punto punto_aux = cola.front();
        cola.pop();

        if(punto_aux.l == e.l && punto_aux.r == e.r && punto_aux.c == e.c) 
			return dungeon[punto_aux.l][punto_aux.r][punto_aux.c];

        if(entrada(punto_aux.l+1, punto_aux.r, punto_aux.c, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l+1][punto_aux.r][punto_aux.c] == -1){
				
            cola.push(Punto(punto_aux.l+1, punto_aux.r, punto_aux.c));
            dungeon[punto_aux.l+1][punto_aux.r][punto_aux.c] = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
        
		}

        if(entrada(punto_aux.l-1, punto_aux.r, punto_aux.c, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l-1][punto_aux.r][punto_aux.c] == -1){
            
			cola.push(Punto(punto_aux.l-1, punto_aux.r, punto_aux.c));
            dungeon[punto_aux.l-1][punto_aux.r][punto_aux.c] = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
			
		}

        if(entrada(punto_aux.l, punto_aux.r+1, punto_aux.c, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l][punto_aux.r+1][punto_aux.c] == -1){
            
			cola.push(Punto(punto_aux.l, punto_aux.r+1, punto_aux.c));
            dungeon[punto_aux.l][punto_aux.r+1][punto_aux.c]  = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
        
		}

        if(entrada(punto_aux.l, punto_aux.r-1, punto_aux.c, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l][punto_aux.r-1][punto_aux.c] == -1){
            
			cola.push(Punto(punto_aux.l, punto_aux.r-1, punto_aux.c));
            dungeon[punto_aux.l][punto_aux.r-1][punto_aux.c] = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
        
		}

        if(entrada(punto_aux.l, punto_aux.r, punto_aux.c+1, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l][punto_aux.r][punto_aux.c+1] == -1){
            
			cola.push(Punto(punto_aux.l, punto_aux.r, punto_aux.c+1));
            dungeon[punto_aux.l][punto_aux.r][punto_aux.c+1] = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
        
		}

        if(entrada(punto_aux.l, punto_aux.r, punto_aux.c-1, maxl, maxr, maxc) 
			&& dungeon[punto_aux.l][punto_aux.r][punto_aux.c-1] == -1){
            
			cola.push(Punto(punto_aux.l, punto_aux.r, punto_aux.c-1));
            dungeon[punto_aux.l][punto_aux.r][punto_aux.c-1] = dungeon[punto_aux.l][punto_aux.r][punto_aux.c]+1;
        
		}

    }

    return -1;
}

int main(){
	
    int l;
    int r;
    int c;
    cin>>l>>r>>c;
    iniciar(l,r,c);
    
    return 0;
}
