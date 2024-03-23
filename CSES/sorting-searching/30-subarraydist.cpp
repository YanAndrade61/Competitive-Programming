#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    map<int, int> freq;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    ll j = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        
        while(j < n && (freq.size() < k  || freq.count(nums[j]) > 0 )) {
            freq[nums[j]]++;
            j++;
        }
        ans += j-i;
        freq[nums[i]]--;
        if(freq[nums[i]] == 0) freq.erase(nums[i]);
    }
   
    cout << ans << endl;

    return 0;
}