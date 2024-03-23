#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int r[2] = {0};
    int prev;
    for (int i = 0; i < 2; i++) {
        prev = 0;
        for (int k = 0; k < 10; k++) {
            int now; cin >> now;
            r[i] += max(0, now-prev);
            prev = now;
        }
    }
    cout << (r[0] < r[1] ? 1 : 2) << endl;

}