#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        ll n, x; cin >> n >> x;
        
        ll children[n];
        for (int i = 0; i < n; i++) cin >> children[i];
        sort(children, children + n);

        int i, j, ans = 0;
        for (i = 0, j = n-1; i <= j;) {
                if(children[j]+children[i] <= x) {
                        i++; j--;
                }
                else  {
                        j--;
                }
                ans++;
        }
        cout << ans << endl;

        return 0;
}