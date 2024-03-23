#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

        int t; cin >> t;
        while(t--){
                ll a,b; cin >> a >> b;
                if((a+b) %3 == 0 && min(a,b) >= max(a,b)/2)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }

        return 0;
}