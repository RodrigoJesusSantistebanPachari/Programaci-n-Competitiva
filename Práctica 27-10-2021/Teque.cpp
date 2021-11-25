#include <bits/stdc++.h>

using namespace std;

void balancear(deque<int> &l1, deque<int> &l2) {
    int diff = l1.size() - l2.size();
    int val;
    if (diff < 0) {
        double d = (double)diff / -2;
        for (int i = 0; i < ceil(d); i++) {
            val = l2.front();
            l2.pop_front();
            l1.push_back(val);
        }
    }
    else if (diff > 1) {
        double d = (double)diff / 2;
        for (int i = 0; i < floor(d); i++) {
            val = l1.back();
            l1.pop_back();
            l2.push_front(val);
        }
    }
}

int main() {
    int n;
    cin >> n;
    deque<int> d1;
    deque<int> d2;
    string command;
    int num;
    for (int i = 0; i < n; i++) {
    	cin>>command;
    	cin>>num;
        if (command[0] == 'g') {
            if (d1.size() > num){
                cout << d1[num] << endl;
            }
            else{
                cout << d2[num - d1.size()]  << endl;
            }
        }
        else if(command[5] == 'b'){
            d2.push_back(num);
            balancear(d1, d2);
        }
        else if(command[5] == 'f'){
            d1.push_front(num);
            balancear(d1, d2);
        }
        else if(command[5] == 'm'){
            d1.push_back(num);
            balancear(d1, d2);
        }
    }

    return 0;
}
