#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++){
        int v; cin >> v;
        arr.push_back({v,i+1});
    }
    sort(arr.begin(), arr.end());

    bool ans = false;
    for (auto p: arr) {
        int v = x-p.first;
        int k = 0;
        for (int b = n / 2; b >= 1; b /= 2)
            while (k + b < n && arr[k + b].first <= v)
                k += b;
        if(p.second == arr[k].second) continue; 
        if(arr[k].first == v) {
            cout << p.second << " " << arr[k].second << endl;
            ans = 1;
            break;
        }
    }
    if(!ans) cout << "IMPOSSIBLE" << endl;
    return 0;
}