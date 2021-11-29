#include <bits/stdc++.h>

#define INF 999999
#define MAX 9999

using namespace std;

int grid (vector<vector<int>>& image,vector<vector<int>>& dist,int r,int c);

int main(){
    int r=0,c=0,x=0,r1=0,s1=0,r2=0,s2=0;
    char d;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c,0));
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));

    for(int i=0; i<r;i++){
        for(int j=0;j<c;j++){
            cin>>d;
            arr[i][j]=d-'0';
        }
    }

    cout<<grid(arr,dist,r,c);    
    return 0;
}



int grid (vector<vector<int>>& image,vector<vector<int>>& dist,int r,int c){
	
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};


    deque<vector<int>> vis;
    vis.push_back({0,0});
    dist[0][0]=0;
    while(!vis.empty()){
    	
        vector<int> op = vis.front();
        vis.pop_front();
        int i = op[0],j=op[1],d=dist[i][j];
        for(int k=0;k<4;k++){
            int xi=i+dx[k]*image[i][j];
            int yj =j+dy[k]*image[i][j];
            if(xi==r-1 && yj==c-1) 
				return d+1;
            if(0<=xi && xi<r && 0<=yj && yj<c && image[xi][yj]!=0 && dist[xi][yj]==INT_MAX){
                vis.push_back({xi,yj});
                dist[xi][yj]=d+1;                
            }
        }
    }
    return -1;

}
