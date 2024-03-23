#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main() {

    int n, x; cin >> n >> x;
    int price[n], page[n];
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> page[i];
    }

    int dp[x+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if(price[i] <= j) {
                dp[j] = max(dp[j], dp[j-price[i]] + page[i]);
            }            
        }
    }
    cout << dp[x] << endl;

    return 0;
}