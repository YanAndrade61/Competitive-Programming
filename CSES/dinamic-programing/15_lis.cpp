#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 0; i < n; i++) {
        if (arr[i] > dp.back()) {
            dp.push_back(arr[i]);
        }
        else {
            int pos = lower_bound(dp.begin(), dp.end(), arr[i]) 
                        - dp.begin();
            dp[pos] = arr[i];
        }
    }

    cout << dp.size() << endl;

    return 0;
}