#include<bits/stdc++.h>
#define ll long long
#define ERR (1e-9)
using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {

        int n; cin >> n;
        ll total = 0;
        while (n--) {
            ll x; cin >> x;
            total += x;
        }

        double raiz = sqrt(total);
        if(abs(raiz - floor(raiz)) < ERR) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    return 0;
}   