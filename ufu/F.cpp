#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;
#define diag(n, m) sqrt(n*n + m*m)

int main()
{

    int l, c, r1, r2;
    while (cin >> l >> c >> r1 >> r2 && l && c && r1 && r2)
    {
        int d1 = 2*r1, d2 = 2*r2;
        if (max(d1,d2) <= l && max(d1,d2) <= c){
            if(diag((l-r1-r2), (c-r1-r2)) >= r1+r2)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }   
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}