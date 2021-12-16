#include <bits/stdc++.h>

using namespace std;

int main() {
	
    int N, T, c, t;
    vector<int> queue(10000, -1);
	vector<pair<int,int>> people(10000);

	cin>>N>>T;

    for (int i = 0; i < N; i++) {
        cin>>c>>t;
        people[i] = pair<int, int>(-c, t); // -c el dinero es ordenado en orden descendente
    }
	
	sort(people.begin(), people.end());

    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        c = -people[i].first; // deshacemos la negación que hicimos al comienzo
        t = people[i].second;
        for (int j = t; j >= 0; j--) {
            if (queue[j] == -1) {
                queue[j] = 1;
                ans += c;
                break;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
