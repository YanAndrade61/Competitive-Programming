#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> dp(n+1, 1);
    for (int i = 10; i <= n; i++) {
        int maxi = 0, x = i;
        while(x > 0) {
            maxi = max(maxi, x%10);
            x /= 10;
        }
        dp[i] = dp[i-maxi]+1;
    }
    
    cout << dp[n] << endl;

    return 0;
}