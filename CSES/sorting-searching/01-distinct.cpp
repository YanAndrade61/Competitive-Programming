#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n; cin >> n;
        set<ll> st;
        int x;
        while(cin >> x) st.insert(x);
        cout << st.size() << endl;

        return 0;
}