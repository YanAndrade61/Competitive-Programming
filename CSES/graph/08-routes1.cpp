#include<bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pll pair<ll,ll>
#define MAXN (int)(1e5 + 1)

using namespace std;

vector<pll> adj[MAXN];
ll dist[MAXN];

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        int v, u, w; cin >> v >> u >> w;
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) dist[i] = LONG_MAX;
    priority_queue<pll> q;
    q.push({0,1});
    dist[1] = 0;
    while(!q.empty()) { 
        int d = -q.top().f, v = q.top().s;
        q.pop();
        if(d > dist[v]) continue;
        for(auto u: adj[v]) {
            if(dist[u.f] > dist[v] + u.s) {
                dist[u.f] = dist[v] + u.s;
                q.push({-dist[u.f],u.f});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}