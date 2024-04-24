#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    getline(cin, str);
    int i = 0;
    for (auto c: str) {
        if(i%2 == 0 && c != ' ') cout << (char)toupper(c);
        else cout << c;
        i = (i+1)%2;
    }
    cout << endl;

    return 0;
}