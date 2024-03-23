#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    
    ll n, x;
    cin >> n >> x;
    vector<pll> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].f; 
        vec[i].s = i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        ll l = 0, r = n-1;
        while(l != r) {
            if(i != l && i != r && vec[l].f + vec[r].f + vec[i].f == x) {
                cout << vec[i].s+1 << " " << vec[l].s+1 << " " << vec[r].s+1;
                cout << endl;
                return 0;
            }
            if(vec[l].f + vec[r].f+vec[i].f < x) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}