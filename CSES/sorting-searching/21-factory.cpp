#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> fact;

ll calc(ll time, ll t) {

        ll total = 0;
        for(auto f: fact) {
                total += time/f;
                if(total >= t) break; //Overflow
        }
        return total;
}

int main() {

        ll n, t; cin >> n >> t;
        
        fact.resize(n);
        for (int i = 0; i < n; i++) cin >> fact[i];

        ll ans = 1e18;
        for (ll i = ans/2; i >= 1; i /= 2)
                while(calc(ans-i, t) >= t)
                        ans-=i;
        cout << ans << endl;

        return 0;
}