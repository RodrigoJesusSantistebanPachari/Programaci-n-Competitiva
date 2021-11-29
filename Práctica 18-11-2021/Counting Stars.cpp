#include <bits/stdc++.h>

using namespace std;


#define MAX_M 100
#define MAX_N 100

int m, n, stars, caseNum = 1;
bool map[MAX_M][MAX_N];
char c;

void dfs(int i, int j);

int main() {
    while (scanf("%d %d", &m, &n) == 2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                scanf(" %c", &c);
                if (c == '-') {
                    map[i][j] = true;
                }
            }
        }
        stars = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j]) {
                    stars++;
                    dfs(i, j);
                }
            }
        }
        printf("Case %d: %d\n", caseNum++, stars);
    }
}

void dfs(int i, int j) {
    if (!map[i][j]) return;
    map[i][j] = false;
    if (i > 0) dfs(i - 1, j);
    if (i < m - 1) dfs(i + 1, j);
    if (j > 0) dfs(i, j - 1);
    if (j < n - 1) dfs(i, j + 1);
}
