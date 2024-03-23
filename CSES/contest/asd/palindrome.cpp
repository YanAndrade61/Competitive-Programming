#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, k; cin >> n >> k;
    string rest = "bcd";
    for (int i = 0; i < n; i++) {
        cout << (i < k ? 'a' : rest[i%3]);
    }
    cout << endl;

    return 0;
}