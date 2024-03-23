#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x+1);
    dp[0] = 1;
    for (auto c: coins) {
        for (int i = 1; i <= x; i++) {
            if(i-c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[x] << endl;       

    return 0;
}