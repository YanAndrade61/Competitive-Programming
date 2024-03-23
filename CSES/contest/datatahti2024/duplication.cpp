#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;

int main() 
{
    string str; cin >> str;
    int sz = str.size();
    vector<char> tmp(MAXN);

    for (int i = 0; i < sz; i++)
        tmp[MAXN - sz - i] = str[i];
    
    int i = MAXN - sz;
    string ans = "";
    while(i < MAXN) {
        if(!isdigit(tmp[i])) {
            ans += tmp[i];
            cout << i << " " << ans << endl;
            i++;            
        } else {
            int d = tmp[i] - '0';
            for (int j = i+1; j < i+d+1; j++)
                tmp[j-d] = tmp[j];
            
            i -= d;
        }
    }
    cout << ans << endl;

}