#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n; cin >> n;
        
        ll coins[n];
        for (int i = 0; i < n; i++) cin >> coins[i];
        sort(coins, coins+n);

        ll ans = 1;
        for (int i = 0; i < n; i++) 
                if(coins[i] <= ans) ans+= coins[i];
        cout << ans << endl;
        
        return 0;
}