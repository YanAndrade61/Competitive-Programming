#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;

int main() {

    int l; cin >> l;
    double r = l/2.0;
    double area = (l*l) - PI*r*r;
    cout << fixed << setprecision(2);
    cout << area << endl;

    return 0;
}