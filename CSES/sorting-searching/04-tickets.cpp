#include <bits/stdc++.h>
using namespace std;

int main() {

        int n, m; cin >> n >> m;
        
        multiset<int> tickets;
        for (int i = 0; i < n; i++) {
                int p; cin >> p;
                tickets.insert(p);
        }

        while(m--) {
                int p; cin >> p;
                auto it = tickets.upper_bound(p);
                if(it == tickets.begin()) {
                        cout << -1 << endl;
                }
                else {
                        cout << *(--it) << endl;
                        tickets.erase(it);
                }
        }

        return 0;
}