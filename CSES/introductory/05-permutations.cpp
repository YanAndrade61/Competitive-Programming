#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

        int n; cin >> n;
        if(n == 3 || n == 2){cout << "NO SOLUTION" << endl; return 0;}
        int par = n&1 ? n-1 : n;
        int impar = n&1 ? n : n-1;

        cout << impar; impar -= 2;
        for (; impar > 0; impar -=2) cout << " " << impar;
        for (; par > 0; par -=2) cout << " " << par;
        cout << endl;

        return 0;
}