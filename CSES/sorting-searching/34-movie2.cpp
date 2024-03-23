#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define s second
#define f first

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = 
        tree<T, null_type, less_equal<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {

        int n, k; cin >> n >> k;
        vector<pair<int,int>> vec(n);
        for (int i = 0; i < n; i++)
                cin >> vec[i].s >> vec[i].f;
        sort(vec.begin(), vec.end());

        int ans = 0;
        oset<pair<int,int>> st;
        for(auto p: vec) {
                int order = st.order_of_key({p.s,p.f});
                if(order > 0)
                        st.erase(st.find_by_order(order-1));
                if((int)st.size() < k) {
                        st.insert({p.f,p.s});
                        ans++;
                }
        }

        cout << ans << endl;
}