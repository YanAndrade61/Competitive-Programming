#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

        int n; cin >> n;
        while(n--){
                ll x,y; cin >> x >> y;
                ll maxl = max(x,y); 
                ll x0 = maxl&1 ? maxl : 0, y0 = maxl - x0;
                ll value = pow(maxl-1,2) + abs(x0-x) + abs(y0-y); 
                cout << value << endl;
        }

        return 0;
}