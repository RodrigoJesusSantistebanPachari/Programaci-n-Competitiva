#include<bits/stdc++.h>

using namespace std;

#define INF 999999

vector<int> match(string cad, string patron) {

	int pos = 0;
	int sp = 0;
	int kp = 0;
	
    vector<int> a;
    vector<int> b(patron.size() + 1, -1);
 
    for(int i = 1; i <= patron.size(); i++) {
        pos = b[i - 1];
        while (pos != -1 && patron[pos] != patron[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }


    while (sp < cad.size()) {
    	
        while (kp != -1 && (kp == patron.size() || patron[kp] != cad[sp])) 
			kp = b[kp];
			
        kp++; 
		sp++;
		
        if (kp == patron.size()) 
			a.emplace_back(sp - patron.size());
    }
    
    return a;
}

int main() {

    string pat;
	string text;
    bool flag;
    
    while (true) {
    	
        if (!getline(cin, pat)) 
			break;
        if (!getline(cin, text)) 
			break;
        auto positions = match(text, pat);
        
		if (!positions.empty()) {
            flag = true;
            for (const auto &i : positions) {
                if (flag) {
                    flag = false;
                } 
				else 
                    cout<<" ";
                cout << i;
            }
        }
        cout<<endl;
    }
    return 0;
}
        
