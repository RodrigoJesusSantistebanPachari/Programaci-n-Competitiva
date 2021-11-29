#include <bits/stdc++.h>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
    }
    for (int j = m - 2; j >= 0; j--) {
      dp[j][n - 1] = max(1, dp[j + 1][n - 1] - dungeon[j][n - 1]);
    }
    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
  
  
int main(){
	
	int n;
	cout<<"n: ";cin>>n;
	
	vector<int> v(n);
	vector<vector<int>> grid;
		
	
	for(int i=0; i<n; i++){
		grid.push_back(v);
		for(int j=0; j<n; j++){
			cin>>grid[i][j];
		}
	}

	cout<<"Output: "<<calculateMinimumHP(grid);

	return 0;
}
