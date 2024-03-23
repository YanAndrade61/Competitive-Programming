#include <bits/stdc++.h>

using namespace std;

int main () {
        ios::sync_with_stdio(false);
	cin.tie(NULL);

        int x, n; cin >> x >> n;
        set<int> traffic;
        multiset<int> gaps;
        traffic.insert(0); traffic.insert(x);
        gaps.insert(x);
        while(n--) {
                int t; cin >> t;
                auto next = traffic.upper_bound(t);
                auto prev = next; --prev;

                traffic.insert(t);
                gaps.erase(gaps.find(*next-*prev));
                gaps.insert(t-*prev);
                gaps.insert(*next-t);
                
                auto ans = gaps.end(); --ans;
                cout << *(ans) << " ";
        }
        cout << endl;
        return 0;
}