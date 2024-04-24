#include<bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define INF (ll)(1e18)
#define MAXN 2500

using namespace std;

vector<pair<ll,pair<int,int>>> edges;
vector<ll> dist;
vector<ll> previ;

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        ll v,u,w; cin >> v >> u >> w;
        edges.push_back({w, {v,u}});
    }

    dist.assign(n+1, 0);
    previ.assign(n+1, 0);
    
    int start;
    for (int i = 0; i < n; i++){
        start = -1;
        for(auto e: edges) {
            ll w = e.f;
            int v = e.s.f, u = e.s.s; 
            if(dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                previ[u] = v;
                start = u;
            }
        }
    }
    if(start == -1) {
        cout << "NO" << endl;
        return 0;
    }

    //Posiciona o start dentro do loop
    for (int i = 0; i < n; i++) {
        start = previ[start];
    }

    vector<int> cycle;
    for (int v = start;; v = previ[v]) {
        cycle.push_back(v);
        if(v == start && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (auto v: cycle) cout << v << " ";
    cout << endl;    

    return 0;
}