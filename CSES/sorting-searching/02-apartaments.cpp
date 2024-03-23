#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        ll n,m,k; cin >> n >> m >> k;
        int i,j;
        vector<ll> need(n);
        for (i = 0; i < n; i++) cin >> need[i];
        sort(need.begin(), need.end());

        vector<ll> ap(m);
        for (i = 0; i < m; i++) cin >> ap[i];
        sort(ap.begin(), ap.end());
        
        int ans = 0;
        for(i = 0, j = 0; i < n && j < m;) {
                if(ap[j] >= need[i]-k && ap[j] <= need[i]+k) {
                        i++; j++; ans++;
                }
                else if(ap[j] < need[i]-k) {
                        j++;
                }
                else {
                        i++;
                }
        }

        cout << ans << endl;

        return 0;
}