#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mini;
int n;

void division(ll arr[], ll set1, ll set2, int i) {
        if(i == n) {
                mini = min(mini, abs(set1-set2));
                return;
        }
        division(arr, set1+arr[i], set2, i+1);
        division(arr, set1, set2+arr[i], i+1);
}

int main() {

        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        mini = INT32_MAX;       
        division(arr, 0, 0, 0);

        cout << mini << endl;

        return 0;
}