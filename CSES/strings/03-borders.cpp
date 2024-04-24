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

    string str; cin >> str;
    
    calculateLPS(str);

    set<int> ans;
    int i = lps[str.size()-1];
    while (i > 0) {
        ans.insert(i);
        i = lps[i-1];
    }

    for(auto v: ans) cout << v << " ";
    cout << endl;

    return 0;
}