#include <bits/stdc++.h>
#define s second
#define f first

using namespace std;

int main() {

        int n; cin >> n;
        vector<pair<int,int>> ranges;
        map<pair<int,int>,int> idx;
        for (int i = 0; i < n; i++) {
                int a,b; cin >> a >> b;
                ranges.push_back( {a, -b});
                idx[{a, -b}] = i;
        }
        sort(ranges.begin(), ranges.end());
        
        vector<bool> contain(n,0), contained(n,0);
        int maxb = 0;
        for (auto p: ranges) {
                if(abs(p.s) <= maxb) contained[idx[p]] = 1;
                maxb = max(maxb, abs(p.s));
        }
        int minb = INT_MAX;
        for (int i = n-1; i >= 0; i--) {
                if(abs(ranges[i].s) >= minb) contain[idx[ranges[i]]] = 1;
                minb = min(minb, abs(ranges[i].s));
        }

        for (auto i: contain) cout << i << " ";
        cout << endl;
        for (auto i: contained) cout << i << " ";
        cout << endl;

        return 0;
}