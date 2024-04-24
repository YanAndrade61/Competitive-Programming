#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
 
template<class T> using min_heap = 
    priority_queue<T, vector<T>, greater<T>>;
 
int main() {
    
    int t; cin >> t;
    while(t--) {
    int n,m;

    cin >> n >> m;
    
    vector<vector<pair<int,long>>> adj(n+1);
    vector<int> bike(n+1);
 
    for(int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
    }
    
    min_heap<pair<long,pair<int,int>>> queue;
    vector<int> vis(n+1,0);
    
    queue.push({0,{1,bike[1]}});
    while(!queue.empty()) {
        int u = queue.top().s.f;
        int bu = queue.top().s.s;
        long du = queue.top().f;
        queue.pop();
 
        if(u == n) {cout << du << endl; break;} 
        if(!vis[u]) {
            vis[u] = 1;
            for(auto edge : adj[u]) {
                int v = edge.f;
                int dv = edge.s;
                queue.push({du+dv*bu,{v,min(bu,bike[v])}});
            }
        } 
    }
    cout << endl;
    } 
    return 0;
}
