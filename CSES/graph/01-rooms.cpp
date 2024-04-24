#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> tab;

void dfs(int i, int j) {

    if(i < 0 || j < 0 || i >= n || j >= m || tab[i][j] == '#') {
        return;
    }
    tab[i][j] = '#';
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}

int main() {

    cin >> n >> m;
    tab.assign(n,vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(tab[i][j] != '#') {
                dfs(i,j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;

    return 0;
}