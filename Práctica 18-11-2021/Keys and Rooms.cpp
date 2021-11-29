#include <bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> reached;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int roomNumber = q.front();
      q.pop();
      reached.insert(roomNumber);
      for (auto key : rooms[roomNumber]) {
        if (reached.count(key) == 0) {
          q.push(key);
        }
      }
    }
    return reached.size() == rooms.size();
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

	cout<<"Output: "<<canVisitAllRooms(grid);
	return 0;
}
