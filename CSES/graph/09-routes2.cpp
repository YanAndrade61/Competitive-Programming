#include<bits/stdc++.h>

#define ll long long
#define MAXN 500
#define MAXI (ll)(1e18)

using namespace std;

ll dist[MAXN][MAXN];

int main() {

    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j ? 0 : MAXI);
        }
    }
    
    while(m--) {
        ll v,u,w; cin >> v >> u >> w;
        v--; u--;
        if(w < dist[u][v]) {
            dist[v][u] = w;
            dist[u][v] = w;
        }
    }

    for (int k  = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {                
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
            }
        }
    }

    while(q--) {
        int v, u; cin >> v >> u;
        v--; u--;
        cout << (dist[v][u] == MAXI ? -1 : dist[v][u]);
        cout << endl;
    }

    return 0;
}