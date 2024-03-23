#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        ll n; cin >> n;
        ll sum=0, maxi=0;
        while (n--) {
                ll t; cin >> t;
                maxi = max(maxi, t);
                sum += t;
        }

        cout << max(2*maxi, sum) << endl;

        return 0;
}