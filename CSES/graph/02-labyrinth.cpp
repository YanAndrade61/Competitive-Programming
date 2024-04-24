#include<bits/stdc++.h>

#define pii pair<int,int>
#define f first
#define s second
#define MAXN 1000

using namespace std;

int n, m;
string ans;
char M[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {

    int prev[MAXN][MAXN];
    int di[] = { 0, 0, -1, 1};
    int dj[] = {-1, 1,  0, 0};
    string dir = "LRUD";

    cin >> n >> m;
    pii src, dest;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
            if(M[i][j] == 'A') src = {i, j};
            if(M[i][j] == 'B') dest = {i, j};
        }
    }

    queue<pii> q;
    q.push(src);
    vis[src.f][src.s] = 1;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        if(M[u.f][u.s] == 'B') {
            break;
        }
        for (int k = 0; k < 4; k++) {
            pii v = {u.f + di[k], u.s + dj[k]}; 
            if(v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
            if(vis[v.f][v.s] || M[v.f][v.s] == '#') continue;
            vis[v.f][v.s] = 1;
            prev[v.f][v.s] = k;
            q.push(v);
        }
    }

    if(!vis[dest.f][dest.s]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    vector<int> path;
    while(dest != src) {
        int k = prev[dest.f][dest.s];
        path.push_back(k);
        dest = {dest.f-di[k], dest.s-dj[k]};    
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    for (auto k: path) cout << dir[k];
    cout << endl;

    return 0;
}