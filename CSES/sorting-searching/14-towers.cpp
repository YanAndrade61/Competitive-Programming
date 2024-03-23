#include<bits/stdc++.h>

using namespace std;

int main() {

        int n; cin >> n;
        multiset<int> towers;
        while(n--) {
                int k; cin >> k;
                auto it = towers.upper_bound(k);
                if(it == towers.end()) {
                        towers.insert(k);
                } else {
                        towers.erase(it);
                        towers.insert(k);
                }
        }
        cout << towers.size() << endl;

        return 0;
}