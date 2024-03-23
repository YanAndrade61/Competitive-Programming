#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k; cin >> n >> k;
    if(k > n-2 || k&1 || n&1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    string ans1 = "";
    for (int i = 0; i < n; i+=2) {
        ans1 += "()";
    }
    string ans2 = ans1;
    for (int i = 1; i <= n-2 && k > 0; i+=2, k-=2) {
        swap(ans2[i], ans2[i+1]);
    }

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}