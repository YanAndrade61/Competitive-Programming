#include <bits/stdc++.h>
using namespace std;

int main() {

        int n; cin >> n;
        vector<pair<int,int>> rest;
        while (n--) {
                int a,b; cin >> a >> b;
                rest.push_back({a,1});                
                rest.push_back({b,-1});                
        }
        sort(rest.begin(), rest.end());
        int ans = 0;
        int preff = 0;
        for (auto r: rest) {
                preff += r.second;
                ans = max(ans,preff);
        }
        cout << ans << endl;
        

        return 0;
}