#include<bits/stdc++.h>

#define ll long long
#define MOD (int)(1e9+7)

using namespace std;

int main() {

    int n;
    cin >> n;
    ll sum = n*(n+1)/2;
    
    if(sum&1) {
        cout << 0 << endl;
        return 0;
    }

    ll value = sum/2;
    ll dp[n][value+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= value; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    
    cout << dp[n-1][value] << endl;

    return 0;
}