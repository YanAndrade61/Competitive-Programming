#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;

int main() {

    string palavra;
    int linhas, passo, sz, inicial=0, att=0;

    cin >> palavra >> linhas;
    sz = palavra.size();
    passo = (linhas - 1)*3;

    vector<char> ans(sz);

    for(int i=0; i<sz; i++){
        ans[att] = palavra[i];
        cout << att << "\n";
        if(att+abs(passo)>=sz){
            inicial++;
            att = inicial;
            passo -= 2;
            if(passo == -1) passo = -3;
        }
        else att+=abs(passo);
    }


    for(auto a: ans){
        cout << a;
    }

    cout << "\n";
    

    return 0;
}