#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define s second
#define f first
#define ll long long

using namespace __gnu_pbds;
using namespace std;
 
template<class T> using oset = 
        tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
 
 
int main() {
 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int,int>> ranges;
        map<pair<int,int>,int> idx;
        for (int i = 0; i < n; i++) {
                int a,b; cin >> a >> b;
                ranges.push_back({a, b});
                idx[{a, b}] = i;
        }
        sort(ranges.begin(), ranges.end());

        
        ll ans = 0;
        oset<pair<int,int>> st;
        for (int i = n-1; i >= 0; i--) {
                pair<int,int> p = {ranges[i].s, n-i};
                st.insert(p);
                ans += st.order_of_key(p);
        }

        cout << ans << endl;
    }

    return 0;
}