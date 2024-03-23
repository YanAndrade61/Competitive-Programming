#include <bits/stdc++.h>

using namespace std;

void move(int start, int end, int help, int n) {
    if (n == 1) {
        cout << start << " " << end << endl;
        return;
    }
    move(start, help, end, n-1);
    move(start, end, help, 1);
    move(help, end, start, n-1);
}

int main()
{

    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;

    move(1, 3, 2, n);

    return 0;
}