#include <bits/stdc++.h>


using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(obstacleGrid, cache, 0, 0, m, n);
}

int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& cache, int i, int j, int m, int n){
        if (obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i + 1 == m && j + 1 == n) {
            return 1;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        int paths = 0;
        if (i + 1 < m) {
            paths += dfs(obstacleGrid, cache, i + 1, j, m, n);
        }
        if (j + 1 < n) {
            paths += dfs(obstacleGrid, cache, i, j + 1, m, n);
        }
        cache[i][j] = paths;
        return paths;
    }


int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	
	cout<<"Output: "<<uniquePathsWithObstacles(v);
	return 0;
}
