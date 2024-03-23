#include <bits/stdc++.h>
#define MOD (int)(1e9 + 7)
using namespace std;

int main() {

    int n; 
    cin >> n;

    char tab[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tab[i][j];
        }
    }

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(tab[i-1][j-1] == '*') continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}