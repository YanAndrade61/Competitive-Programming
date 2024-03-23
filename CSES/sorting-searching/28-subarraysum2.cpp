#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

        int n, k; cin >> n >> k;
        
        map<ll,ll> mp;
        mp[0] = 1;
        
        ll acc = 0, ans = 0;
        while(n--) {
                ll x; cin >> x;
                acc += x;
                ans += mp[acc-k];
                mp[acc]++;
        }
        cout << ans << endl;
        return 0;
}