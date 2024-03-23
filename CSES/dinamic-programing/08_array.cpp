#include <bits/stdc++.h>
#define MOD (int)(1e9+7)
#define ll long long
using namespace std;

int main() {

    int n, m; 
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll dp[n][m+2];
    memset(dp, 0, sizeof(dp));
    if(arr[0] != 0) {
        dp[0][arr[0]] = 1;
    } else {
        for(int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        int v = arr[i];
        if(v != 0) {
            dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]; 
            dp[i][v] %= MOD;
        } else {
            for(v = 1; v <= m; v++) {
                dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1];
                dp[i][v] %= MOD;
            }    
        }
    }
    
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}