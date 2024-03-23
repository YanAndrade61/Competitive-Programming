#include <bits/stdc++.h>

#define ll long long
#define s second
using namespace std;

int main() {

        int n; cin >> n;
        map<ll,ll> mp;
        mp[0] = 1;
        ll acc = 0;
        for (int i = 0; i < n; i++) {
                ll x; cin >> x;
                acc += x;
                mp[(acc%n + n) % n]++;
        }
        
        ll ans = 0;
        for (auto i: mp) ans += (i.s*(i.s-1)/2);
        cout << ans << endl;

        return 0;
}