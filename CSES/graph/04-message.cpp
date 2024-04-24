#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second

using namespace std;


int main() {

    int n, m; cin >> n >> m;
    vector<bool> vis(n, false);
    vector<vector<int>> adj(n);
    vector<int> prev(n);

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(v == n-1) break;
        for(int u: adj[v]) {
            if(vis[u]) continue;
            vis[u] = true;
            prev[u] = v;
            q.push(u);
        } 
    }
    
    if(!vis[n-1]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> nodes;
    int end = n-1;
    while(end != 0) {
        nodes.push_back(end);
        end = prev[end];
    }
    reverse(nodes.begin(), nodes.end());
    
    cout << nodes.size()+1 << endl;
    cout << 1;
    for(auto v: nodes) cout << " " << v+1;
    cout << endl;

    return 0;
}