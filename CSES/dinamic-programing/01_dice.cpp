#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> count(n + 1, 0);
    count[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 6; k++) {
            if (i - k >= 0) {
                count[i] += count[i - k];
                count[i] %= mod;
            }
        }
    }

    cout << count[n] << endl;

    return 0;
}