#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){

        int n; cin >> n;
        int ans = 1;
        while(n--){
                ans *= 2;
                ans %= mod;
        }
        cout << ans << endl;

        return 0;
}