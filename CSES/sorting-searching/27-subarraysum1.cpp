#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

        int n, k; cin >> n >> k;
        
        set<ll> st;
        st.insert(0);
        
        ll acc = 0, ans = 0;
        while(n--) {
                ll x; cin >> x;
                acc += x;
                
                if(acc >= k && st.find(abs(k-acc)) != st.end()) ans++;

                st.insert(acc);
        }
        cout << ans << endl;
        return 0;
}