#include <bits/stdc++.h>
#define ll long long
using namespace std;

int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main()
{

    int l, c;
    cin >> l >> c;

    ll mt[l][c];

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            cin >> mt[i][j];

    int xi, yi;
    cin >> xi >> yi;
    xi--; yi--;

    for (int i = 0; i < l + c + 1; i++) {
        int vz = 0;
        for (int k = 0; k < 8; k++)
            if (xi + di[k] < 0 || xi + di[k] >= l || yi + dj[k] < 0 || yi + dj[k] >= c) continue;
            else vz++;


        ll dist = mt[xi][yi] / vz;
        mt[xi][yi] %= vz;

        ll maxlocal = 0, mv;
        for (int k = 0; k < 8; k++) {
            int tmpi = xi + di[k], tmpj = yi + dj[k];

            if (tmpi < 0 || tmpi >= l || tmpj < 0 || tmpj >= c)
                continue;

            mt[tmpi][tmpj] += dist;

            if (mt[tmpi][tmpj] > maxlocal) {
                maxlocal = mt[tmpi][tmpj];
                mv = k;
            }
        }
        xi += di[mv];
        yi += dj[mv];

    }

    ll maxi = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            maxi = max(maxi, mt[i][j]);
    cout << maxi << endl;

    return 0;
}