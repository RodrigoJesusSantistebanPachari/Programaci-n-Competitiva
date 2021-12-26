#include<bits/stdc++.h>

using namespace std;
int main(){
    int data_num=0;
    cin>>data_num;
    for(int i=0;i<data_num;i+=1){
    	
        string str;
        cin >> str;
        int str_len = str.size();
        string sub = str;
        for(int j=0;j<str_len;j+=1) {
            rotate(&str[0], &str[0]+1,&str[0]+str_len);
            if(sub > str){
                sub = str;
            }
        }
        cout << sub << endl;
    }
}
