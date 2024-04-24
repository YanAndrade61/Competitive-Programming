#include<bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define INF (ll)(1e18)
#define MAXN 2500

using namespace std;

vector<pair<int,ll>> adj[MAXN];
vector<int> radj[MAXN];
vector<ll> dist;
vector<ll> cycle;
vector<int> vis;

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        ll v,u,w; cin >> v >> u >> w;
        v--; u--;
        adj[v].push_back({u, w});
        radj[u].push_back(v);
    }

    cycle.assign(n, 0);
    dist.assign(n, -INF);
    dist[0] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for(auto e: adj[j]) {
                if(dist[e.f] < dist[j] + e.s) {
                    dist[e.f] = dist[j] + e.s;
                    if(i == n-1) {
                        cycle[e.f] = 1;
                        cycle[j] = 1;
                    }
                }
            }
        }
    }
    
    vis.assign(n, 0);
    bool loop = false;
    queue<pair<int,int>> q;
    q.push({n-1,cycle[n-1]});
    vis[n-1]++;
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        if(v.f == 0 && v.s) {
            loop = true;
            break;
        }
        for(auto u: radj[v.f]) {
            if(vis[u] >= 2) continue;
            vis[u]++;
            q.push({u, cycle[u]|v.s});
        }
    }

    cout << (loop ? -1 : dist[n-1]) << endl;

    return 0;
}