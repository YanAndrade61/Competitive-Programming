#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define f first
#define s second

int main() {

        int n; cin >> n;
        stack<pii> st;
        st.push({0,0});
        for (int i = 1; i <= n; i++) {
                int x; cin >> x;
                while(!st.empty() && st.top().f >= x) st.pop();
                
                if(i > 0) cout << " ";                
                cout << st.top().s;

                st.push({x,i});
        }
        cout << endl;

        return 0;
}
