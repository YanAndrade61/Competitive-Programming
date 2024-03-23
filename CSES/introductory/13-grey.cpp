#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int main(){

        int n; cin >> n;
        int maxi = pow(2,n), atual = 0;
        map<int,int> exist;
        while(maxi--) { 
                cout << bitset<32>(atual).to_string().substr(32-n) << endl;
                exist[atual] = 1;
                for (int i = 0; i < n; i++) {
                        if(!exist[atual^(1 << i)]){
                                atual = atual^(1 << i);
                                break;
                        }
                }
        }

        return 0;
}