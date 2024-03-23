#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = 
        tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {

        int n, k = 1; cin >> n;
        oset<int> children;
        for (int i = 1; i <= n; i++) children.insert(i);
        
        int idx = 0;
        while(children.size() > 1) {
                idx = (idx+k)%children.size();
                cout << *(children.find_by_order(idx)) << " ";
                children.erase(children.find_by_order(idx));
        }
        
        cout << *(children.find_by_order(0)) << endl;

        return 0;
}