#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    
    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n);
    map<ll,pll> mp;

    for (int i = 0; i < n; i++) cin >> vec[i];
    
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            mp[vec[i] + vec[j]] = {i,j};
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll target = x-vec[i]-vec[j];
            if(mp.find(target) != mp.end() &&
               mp[target].f != i && mp[target].s != j &&
               mp[target].s != i && mp[target].f != j) {
                cout << i+1 << " " << j+1 << " ";
                cout << mp[target].f+1 << " " << mp[target].s+1;
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}