#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second
#define MAXN (int)(1e5 + 1)

using namespace std;

vector<int> adj[MAXN];
bool vis[MAXN];
stack<int> st;
bool inSt[MAXN];

bool dfs(int v) {
    
    vis[v] = true;
    inSt[v] = true;
    st.push(v);
    for(auto u: adj[v]) {
        if(!vis[u]) 
            if(dfs(u)) 
                return true;
        if(inSt[u]) {
            st.push(u);
            return true;
        }
    }
    st.pop();
    inSt[v] = false;
    
    return false;
}

int main() {

    int n, m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i)) {
                found = true;
                break;
            }
        }
    }

    if(!found) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cycle;
    int start = st.top();
    while(!st.empty()) {
        cycle.push_back(st.top());
        st.pop();
        if(start == cycle.back() && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for(auto v: cycle) cout << v << " ";
    cout << endl;

    return 0;
}       