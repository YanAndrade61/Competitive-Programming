#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nums[x-1] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += (nums[i] < nums[i-1]);
    }
    cout << ans << endl;

    return 0;
}