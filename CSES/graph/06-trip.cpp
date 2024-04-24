#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second
#define MAXN (int)(1e5)

using namespace std;

bool vis[MAXN];
vector<int> adj[MAXN];
vector<int> cycle;
bool found;

void dfs(int v, int parent) {
    if(found) return;
    if(vis[v]) {
        cycle.push_back(v);
        reverse(cycle.begin(), cycle.end());
        while(cycle.back() != v) cycle.pop_back();

        cout << cycle.size() << endl;
        for(auto c: cycle) cout << c+1 << " "; 
        cout << endl;
        found = true;
        return;
    }
    vis[v] = 1;
    cycle.push_back(v);
    for (auto u: adj[v]) {
        if(u == parent) continue;
        dfs(u, v);
    }   
    cycle.pop_back();
}

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    found = false;
    for (int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }

    if(!found) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}