#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define s second
#define f first

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = 
        tree<T, null_type, less_equal<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {

        int n, k; cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        int start = 0;
        oset<int> window;
        for(auto xi: nums) {
                window.insert(xi);

                if((int)window.size() >= k) {
                        cout << *window.find_by_order(((k - 1)/2)) << " ";
                        auto it = window.upper_bound(nums[start]);  
                        window.erase(it);   

                        start++;        
                }
        }

        cout << endl;

        return 0;
}