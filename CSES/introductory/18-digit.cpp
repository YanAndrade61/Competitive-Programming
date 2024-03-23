#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    vector<ll> pref = {0};
    for (int i = 0; i < 18; ++i) {
        pref.push_back((i + 1) * (9 * static_cast<ll>(pow(10, i))) + pref.back());
    }

    int q; cin >> q;

    while (q--) {
        ll k; cin >> k;

        int ndigits = 0;
        for (int i = 0; i < pref.size(); ++i) {
            if (pref[i] >= k) {
                ndigits = i;
                k -= pref[i - 1];
                break;
            }
        }

        ll digit = k % ndigits;
        ll jump = k / ndigits;
        if (digit == 0) digit = ndigits;
        else jump += + 1;

        cout << to_string(static_cast<ll>(pow(10, ndigits - 1)) + jump - 1)[digit - 1] << endl;
    }

    return 0;
}
