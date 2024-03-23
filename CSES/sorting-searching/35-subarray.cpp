#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n, a, b; cin >> n >> a >> b;
        vector<ll> pref(n+1,0);
        for (int i = 1; i <= n; i++) {
                ll xi; cin >> xi;
                pref[i] = pref[i-1] + xi;
        }
        multiset<ll> ms;
        ll ans = -LONG_LONG_MAX;
        for (int i = a; i <= n; i++) {
 
                if(i > b) {
                        ms.erase(ms.find(pref[i-b-1])); 
                }
                ms.insert(pref[i-a]);
                ans = max(ans, pref[i] - *ms.begin());

        }
        cout << ans << endl;

        return 0;
}