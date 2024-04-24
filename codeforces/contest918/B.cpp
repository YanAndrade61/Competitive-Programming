#include<bits/stdc++.h>

using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {

        map<char,int> count;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char x; cin >> x;
                count[x]++;
            }
        }
        for (auto p: count) {
            if(p.second == 2) {
                cout << p.first << endl;
            }
        }
    }

    return 0;
}