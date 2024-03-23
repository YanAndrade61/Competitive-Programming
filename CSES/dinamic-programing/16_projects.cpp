#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long

using namespace std;

int main() {

    int n; 
    cin >> n;

    // {end, {start, value}} - for sorting by end
    vector<pair<int, pair<int, int>>> proj(n);
    for (int i = 0; i < n; i++) {
        cin >> proj[i].s.f >> proj[i].f >> proj[i].s.s;
    }
    sort(proj.begin(), proj.end());
    
    set<pair<int,ll>> dp;
    dp.insert({0,0});
    ll maxi = 0;
    for (auto p: proj) {
        auto it = dp.lower_bound({p.s.f, 0});
        it--;
        maxi = max(maxi, p.s.s + (*it).s);
        dp.insert({p.f, maxi});
    }
    
    cout << maxi << endl;    


    return 0;
}