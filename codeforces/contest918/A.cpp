#include<bits/stdc++.h>

using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {

        int ans = 0;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            ans ^= x;
        }
        cout << ans << endl;
    }

    return 0;
}