#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> nums;

bool check(ll maxi, int k) {
    ll acc = 0, groups = 0;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] > maxi) return false;
        if (acc + nums[i] > maxi) {
            groups++;
            acc = 0;
        }
        acc += nums[i];
    }
    if (acc > 0) groups++;
    return groups <= k;
}

int main() {
    ll n, k; 
    cin >> n >> k;
    
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    ll r = 2e5 * 1e9, l = 1;
    while(l < r) {
        ll mid = (r + l)/2;

        if(check(mid, k))   r = mid;
        else l = mid + 1;

    }
    
    cout << l << endl;

    return 0;
}
