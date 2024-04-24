#include<bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pll pair<ll,ll>
#define MAXN (int)(1e5 + 7)

using namespace std;

vector<pll> adj[MAXN];
ll dist[MAXN];
ll disc[MAXN];
bool vis[MAXN];

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        int v,u,w; cin >> v >> u >> w;
        adj[v].push_back({u, w});
    }
    
    for (int i = 2; i <= n; i++) disc[i] = dist[i] = LONG_MAX;

    priority_queue<pair<ll,pll>> q;
    q.push({0, {1,0}});

    while(!q.empty()) {
        ll d = -q.top().f;
        ll v = q.top().s.f;
        ll coupon = q.top().s.s;
        q.pop();
        
        if(coupon && d > disc[v]) continue;
        if(!coupon && d > dist[v]) continue;

        for(auto e: adj[v]) {
            int u = e.f, w = e.s;
            if(!coupon) {
                if(dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;
                    q.push({-dist[u],{u, 0}});
                }
                if(disc[u] > dist[v] + w/2) {
                    disc[u] = dist[v] + w/2;
                    q.push({-disc[u],{u, 1}});
                }    
            } else {
                if(disc[u] > disc[v] + w) {
                    disc[u] = disc[v] + w;
                    q.push({-disc[u],{u, 1}});
                }
            }
        }
    }

    cout << disc[n] << endl;

    return 0;
}