#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

        int n, k; cin >> n >> k;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        if(k == 1) {
                for (int i = 0; i < n; i++) cout << 0 << " ";
                cout << endl;
                return 0;
        }

        vector<ll> aux(nums.begin(), nums.begin()+k);
        sort(aux.begin(), aux.end());

        multiset<ll> left, right;
        ll lsum = 0, rsum = 0, lsz = ceil(k/2.0), rsz = k/2;
        for (int i = 0; i < k; i++) {
                if(i < lsz) {
                        left.insert(aux[i]);
                        lsum += aux[i];
                } else {
                        right.insert(aux[i]);
                        rsum += aux[i];
                }
        }

        int start = 0;
        for (int i = k; i <= n; i++, start++) {
                ll med = *left.rbegin();
                cout << lsz*med - lsum + rsum - rsz*med << " ";
                if(i == n) break;

                if(left.find(nums[start]) != left.end()) {
                        left.erase(left.find(nums[start]));
                        lsum -= nums[start];
                        int xi = *right.begin();
                        left.insert(xi);
                        right.erase(right.begin());
                        lsum += xi;
                        rsum -= xi;
                }
                else {
                        right.erase(right.find(nums[start]));
                        rsum -= nums[start];
                }

                med = *left.rbegin();
                if(nums[i] > med) {
                        right.insert(nums[i]);
                        rsum += nums[i];
                }
                else {
                        left.insert(nums[i]);
                        lsum += nums[i];
                        med = *left.rbegin();
                        right.insert(med);
                        left.erase(left.find(med));
                        lsum -= med;
                        rsum += med;
                }
        }
        
        cout << endl;

        return 0;
}