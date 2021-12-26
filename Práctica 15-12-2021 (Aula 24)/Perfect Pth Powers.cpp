#include <bits/stdc++.h>
 
#define INF 9999999 
 
using namespace std;


int main() {

    long long n;
    bool flag;
    while (cin >> n && n != 0) {
    	
        flag = (n < 0);
        n = abs(n);
        long long cur = 2;
        while (1) {
            if (cur * cur > n) {
                cout << "1\n";
                break;
            }
            if (n % cur == 0) {
                long long nn = n, cnt = 0;
                bool flg = 0;
                while (1) {
                    if (nn == 1) {
                        flg = 1;
                        break;
                    }
                    if (nn % cur != 0) break;
                    nn /= cur;
                    cnt++;
                }
                if (flg && (cnt % 2 == 1 || !flag)) {
                    cout << cnt <<endl;
                    break;
                }
            }
            cur++;
        }
    }
    


    return 0;
}
