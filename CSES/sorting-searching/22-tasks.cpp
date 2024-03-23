#include <bits/stdc++.h>

#define pll pair<ll,ll>
#define f first
#define s second
#define ll long long

using namespace std;

int main() {

        int n; cin >> n;
        vector<pll> tasks(n);
        for (int i = 0; i < n; i++) {
                cin >> tasks[i].f >> tasks[i].s;
        }
        sort(tasks.begin(), tasks.end());
        ll ans = 0, time = 0;
        for (auto p : tasks) {
                time += (p.f);
                ans += (p.s-time);
        }
        cout << ans << endl;
}