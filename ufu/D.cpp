#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;

int main() {

    float n, a; cin >> n >> a;
    float V = a/n;
    float b, B, H; cin >> b >> B >> H;
    float h = (3*V) / ((B*B + B*b + b*b) * PI);
    
    cout << fixed << setprecision(2);
    cout << h << endl;

    return 0;
}