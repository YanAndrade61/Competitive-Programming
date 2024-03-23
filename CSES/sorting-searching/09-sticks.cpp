#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n; cin >> n;
        
        ll sticks[n];
        for(int i = 0; i < n; i++) cin >> sticks[i];
        sort(sticks, sticks+n);                

        ll mid = sticks[n/2];
        ll ans = 0;
        for(auto p: sticks) ans += abs(mid-p);
        cout << ans << endl;

        return 0;
}