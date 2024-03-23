#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define s second
#define f first

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = 
        tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;


int main() {

        int n; cin >> n;
        vector<pair<int,int>> ranges;
        map<pair<int,int>,int> idx;
        for (int i = 0; i < n; i++) {
                int a,b; cin >> a >> b;
                ranges.push_back( {a, -b});
                idx[{a, -b}] = i;
        }
        sort(ranges.begin(), ranges.end());
        
        vector<int> contain(n,0), contained(n,0);
        oset<pair<int,int>> st;
        for (int i = 0; i < n; i++) {
                pair<int,int> p = {abs(ranges[i].s), n-i};
                st.insert(p);
                contained[idx[ranges[i]]] = st.size() - st.order_of_key(p) - 1;
        }
        st.clear();
        for (int i = n-1; i >= 0; i--) {
                pair<int,int> p = {abs(ranges[i].s), n-i};
                st.insert(p);
                contain[idx[ranges[i]]] = st.order_of_key(p);
        }
        
        for (auto i: contain) cout << i << " ";
        cout << endl;
        for (auto i: contained) cout << i << " ";
        cout << endl;

        return 0;
}