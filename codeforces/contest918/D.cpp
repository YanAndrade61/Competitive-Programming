#include<bits/stdc++.h>

using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {

        int n; cin >> n;
        string str; cin >> str;
        int i = 2;
        int vogal[] = {1,0,0,0,1};
        cout << str[0] << str[1];
        while(i < n) {
            if(i+1 < n){
                if(!vogal[str[i+1]-'a']) {
                    cout << str[i];
                    i++;
                }else {
                    cout << '.' << str[i] << str[i+1];
                    i+=2;
                }
            } else {
                cout << str[i];
                i++;
            }
        }
        cout << endl;

    }

    return 0;
}   