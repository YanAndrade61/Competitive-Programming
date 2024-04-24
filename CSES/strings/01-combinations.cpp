#include <bits/stdc++.h>

#define MAXW (int)(1e6)
#define MOD (int)(1e9+7)
#define SZ(x) (int)x.size()

using namespace std;

int trie[MAXW][26];
int node_count;
bool stop[MAXW];

void insert(string word) {

    int node = 0;
    for(auto c: word) {
        if(trie[node][c-'a'] == 0) trie[node][c-'a'] = ++node_count;
        node = trie[node][c-'a'];
    }
    stop[node] = true;
}

int main() {

    string str; cin >> str;
    int n; cin >> n;
    while(n--) {
        string word; cin >> word;
        insert(word);
    }

    int dp[SZ(str) + 1];
    memset(dp, 0, sizeof(dp));

    dp[SZ(str)] = 1;
    for (int i = SZ(str)-1; i >= 0; i--) {
        int node = 0;
        for (int j = i; j < SZ(str); j++) {
            if(trie[node][str[j]-'a'] == 0) break;
            
            node = trie[node][str[j]-'a'];

            if(stop[node]) dp[i] = (dp[i] + dp[j+1]) % MOD;
        }
    }
    cout << dp[0] << endl;
    return 0;
}