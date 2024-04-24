#include <bits/stdc++.h>

using namespace std;

int main() {

    int G; cin >> G;
    int mini = 0, maxi = 0;
    int atual = 0;
    char c;
    while(cin >> c) {
        if(c == 'D') atual+=G;
        else atual-=G;
        mini = min(mini, atual);
        maxi = max(maxi, atual);
    }
    
    if(abs(maxi-mini) >= 360) cout << "S";
    else cout << "N";
    cout << endl;


    return 0;
}