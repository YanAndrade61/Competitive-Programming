#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n; cin >> n;
        ll sum = 0, maxi = -INT_MAX;
        while(n--) {
                if(sum < 0) sum = 0;
                ll x; cin >> x;
                sum += x;
                maxi = max(maxi, sum);
        }
        cout << maxi << endl;

        return 0;
}