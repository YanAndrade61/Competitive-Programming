#include<bits/stdc++.h>
#define MAXN (int)(2e6+7)
using namespace std;

int lps[MAXN];

void calculateLPS(string str) {
    
    int n = str.size();
    for (int i = 1, j = 0; i < n; i++) {
        while(j > 0 && str[i] != str[j]) j = lps[j-1];
        if(str[i] == str[j]) j++;
        lps[i] = j;
    }
}

int main() {

    string text, pattern;
    cin >> text >> pattern;
    
    string str = pattern + '#' + text;
    calculateLPS(str);

    int ans = 0;
    for (auto v: lps) {
        if(v == pattern.size()) ans++;
    }
    cout << ans << endl;

    return 0;
}