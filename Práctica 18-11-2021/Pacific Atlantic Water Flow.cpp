#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return matrix;
		}

		int n = matrix.size();
		int m = matrix[0].size();

		static int f4 = 4;
		static int f8 = 8;
		static int f2 = 2;
		static int f1 = 1;

		vector<pair<int, int>> initPos = {{0, 0}, {0, 0}, {n-1, m-1}, {n-1, m-1}};
		static vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		static vector<pair<int, int>> vf = {{f4, f1}, {f4, f1}, {f8, f2}, {f8, f2}};

		vector<vector<int>> flags(n, vector<int>(m, f4 | f8));

		// check parcific
		stack<pair<int, int>> stk;
		for (size_t k = 0; k < initPos.size(); k++) {
			int unvisitFlag = vf[k].first;
			int connFlag = vf[k].second;

			int i = initPos[k].first, j =  initPos[k].second;
			while (i >= 0 && i < n && j >= 0 && j < m) {
				if ((flags[i][j] & unvisitFlag) != 0) {
					flags[i][j] = (flags[i][j] & ~unvisitFlag) | connFlag;
					stk.push(make_pair(i, j));
					while(!stk.empty()) {
						int ii = stk.top().first;
						int jj = stk.top().second;
						stk.pop();
						for (auto& d : delta) {
							int x = ii + d.first;
							int y = jj + d.second;
							if (x >= 0 && x < n && y >= 0 && y < m && (flags[x][y] & unvisitFlag) != 0 && matrix[x][y] >= matrix[ii][jj]) {
								flags[x][y] = (flags[x][y] & ~unvisitFlag) | connFlag;
								stk.push(make_pair(x, y));
							}
						}
					}
				}
				
				i += delta[k].first;
				j += delta[k].second;
			}
		}

		vector<vector<int>> res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (flags[i][j] == (f1 | f2)) {
					res.push_back({i, j});
				}
			}
		}

		return res;
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

	return 0;
}
