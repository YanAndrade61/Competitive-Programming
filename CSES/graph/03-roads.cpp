#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second
#define MAXN (int)(1e5)


using namespace std;

vector<bool> vis;
vector<vector<int>> adj;

void dfs(int v) {
    if(vis[v]) return;
    vis[v] = 1;
    for (auto u: adj[v]) {
        dfs(u);
    }   
}

int main() {

    int n, m; cin >> n >> m;
    adj.resize(n);
    vis.assign(n,false);
    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            nodes.push_back(i);
        }
    }
    
    cout << nodes.size()-1 << endl;
    for (int i = 0; i < nodes.size()-1; i++) {
        cout << nodes[i]+1 << " " << nodes[i+1]+1;
        cout << endl;
    }

    return 0;
}