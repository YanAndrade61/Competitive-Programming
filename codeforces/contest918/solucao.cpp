#include <bits/stdc++.h>
using namespace std;
 
template<class T> using min_heap = 
    priority_queue<T, vector<T>, greater<T>>;
 
int main() {
    int n,m,k;
 
    cin >> n >> m >> k;
    
    // adj[i] = {(vertice, dist)...}
    vector<vector<pair<int,long>>> adj(n+1);
 
    for(int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    min_heap<pair<long,int>> queue; // (dist, vertice)
    vector<int> vis(n+1,0); // conta quantas vezes o vertice foi visitado
    
    queue.push({0,1});
    while(!queue.empty() && vis[n] < k) {
        int u = queue.top().second;
        long du = queue.top().first;
        queue.pop();
 
        vis[u]++;
        if(u == n) cout << du << ' '; 
        if(vis[u] <= k) {
            for(auto edge : adj[u]) {
                int v = edge.first;
                int dv = edge.second;
                queue.push({du+dv,v});
            }
        } 
    }
    cout << endl;
 
    return 0;
}
