#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

        int n; cin >> n;
        for (int i = 1; i <= n; i++){
                ll n2 = i*i;
                ll all = n2*(n2-1)/2;
                ll attack = 2 * 2*(i-2)*(i-1);
                cout << all - attack << endl;
        }

        return 0;
}