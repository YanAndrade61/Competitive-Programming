#include<bits/stdc++.h>

using namespace std;

int main() {

    string str1, str2;
    cin >> str1 >> str2;
    int n = (int)str1.size(), m = (int)str2.size(); 
    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if(i == 0) {
                dp[i][j] = j;
            }
            else if(j == 0) {
                dp[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(
                    dp[i-1][j-1], //Replace   
                    min(dp[i-1][j],   //Insert
                    dp[i][j-1])    //Remove
                );
            }
        }
    }
    cout << dp[n][m] << endl;    

    return 0;
}