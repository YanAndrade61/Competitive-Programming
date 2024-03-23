#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

bool grid[9][9];
int diri[] = {-1,0,1,0};
int dirj[] = {0,1,0,-1};

int ans;
int path[48];

int move(int idx, int i, int j) {

    // for (int i = 1; i < 8; i++){
    //     for (int j = 1; j < 8; j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    if (i >= 8 || i <= 0 || j >= 8 || j <= 0 || grid[i][j])
        return 0;

    if (( grid[i][j-1] &&  grid[i][j+1]) && 
        (!grid[i-1][j] && !grid[i+1][j]))
        return 0;
    if (( grid[i-1][j] &&  grid[i+1][j]) && 
        (!grid[i][j-1] && !grid[i][j+1]))
        return 0;

    if (i == 7 && j == 1) {
        if (idx == 48) ans++;
        else return 0;
    }

    if (idx == 48) return 0;

    grid[i][j] = 1;
    if (path[idx] != 4) {
        move(idx+1, i+diri[path[idx]], j+dirj[path[idx]]);
    }
    else {
        for(int k = 0; k < 4; k++)
            move(idx+1, i+diri[k], j+dirj[k]);
    }
    grid[i][j] = 0;

    return 0;
}

int main() {
    map<char, int> code = {
        {'U', 0},
        {'R', 1},
        {'D', 2},
        {'L', 3},
        {'?', 4},
    };
    
    for(int i = 0; i < 48; i++) {
        char c; cin >> c;
        path[i] = code[c];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(i == 0 || i == 8 || j == 0 || j == 8)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    ans = 0;
    move(0,1,1);

    cout << ans << endl;
}