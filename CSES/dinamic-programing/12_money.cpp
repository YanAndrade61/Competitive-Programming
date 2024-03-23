#include <bits/stdc++.h>

#define MAXSUM (int)(1e6)

using namespace std;

int main() {

    int n;
    cin >> n;
    int money[n], maxsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
        maxsum += money[i];
    }

    set<int> ans;
    bool dp[n+1][maxsum+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= maxsum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-money[i-1] >= 0 && dp[i-1][j-money[i-1]]) {
                dp[i][j] = 1;
            }
            if(j > 0 && dp[i][j]) {
                ans.insert(j);
            }
        }
    }

    cout << ans.size() << endl;
    for(auto a: ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}