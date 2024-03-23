#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; 
    cin >> n;       
    ll arr[n], total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    ll dp[n][n];
    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                dp[i][j] = arr[i];
                continue;
            }
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]); 
        }
    }   
    
    cout << (total + dp[0][n-1]) / 2 << endl;



    return 0;
}