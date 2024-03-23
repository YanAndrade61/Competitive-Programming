#include <bits/stdc++.h>

using namespace std;

int acc;
vector<string> tab(8);
vector<vector<int>> queen(8,vector<int>(8));

int verify(int i, int j) {

    if(i >= 8 && j >= 8) return 1;
    if(tab[i][j] == '*') return 1;

    for (int row = 0; row < i; row++)
        if(queen[row][j]) return 1;

    for (int col = 0; col < j; col++)
        if(queen[i][col]) return 1;
    
    for (int row = i, col = j; row >= 0 && col >= 0; row--, col--)
        if(queen[row][col]) return 1;
    
    for (int row = i, col = j; row < 8 && col >= 0; row++, col--)
        if(queen[row][col]) return 1;

    return 0;
}

void play(int col, int n) {
    if(n == 8) { 
        acc++;
        return;
    }
    
    for (int row = 0; row < 8; row++)
    {
        if(!verify(row, col)) {
            queen[row][col] = 1;
            play(col+1,n+1);
            queen[row][col] = 0;
        }
    }
} 

int main() {
    
    for (int i = 0; i < 8; i++) cin >> tab[i];
    acc = 0;
    play(0,0);
    cout << acc << endl;

    return 0;
}