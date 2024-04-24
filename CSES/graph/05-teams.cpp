#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second
#define MAXN (int)(1e5)

using namespace std;

int color[MAXN];
vector<int> adj[MAXN];
bool impossible;

void dfs(int v, int vc) {
    if(color[v] != 0) return;
    color[v] = vc;
    int uc = (vc%2)+1;
    for(int u: adj[v]) {
        if(color[u] == vc) {
            impossible = true; 
            return;
        }
        dfs(u, uc);
    }
}

int main() {

    int n, m; cin >> n >> m;

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    impossible = false;
    for (int i = 0; i < n; i++) {
        if(color[i] == 0) {    
            dfs(i,1);
        }
    }
    
    if(impossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int i = 0; i < n; i++) cout << color[i] << " ";
        cout << endl;
    }

    return 0;
}