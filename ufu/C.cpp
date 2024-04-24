#include <bits/stdc++.h>
#define ll long long
#define MAXN 100100
#define MOD (int)(1e18)
using namespace std;

int main()
{

    vector<ll> dp(MAXN,0);
    dp[0] = 1;

    int t, maxn = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (dp[n] != 0)
        {
            cout << dp[n] << endl;
            continue;
        }

        for (int i = maxn; i <= n; i++) {
            if (dp[i] != 0)
                continue;
            for (int j = 1; j <= 2; j++)
            {
                if (i - j >= 0){
                    dp[i] += dp[i - j];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[n] << endl;
        maxn = max(maxn, n);
    }

    return 0;
}