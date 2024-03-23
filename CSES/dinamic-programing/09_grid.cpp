#include <bits/stdc++.h>

#define MOD  1000000007
#define MAXN 1000001
#define ll long long

using namespace std;
ll dp[MAXN][2];

int main() {

    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i < MAXN; i++) {
        dp[i][0] = (dp[i][0] + 2*dp[i-1][0]) % MOD;
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;   
        dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        dp[i][1] = (dp[i][1] + 4*dp[i-1][1]) % MOD;
    }

    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        ll ans = (dp[n][0] + dp[n][1]) % MOD;
        cout << ans << endl;
    }

    return 0;
}