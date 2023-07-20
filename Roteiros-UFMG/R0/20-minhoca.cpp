#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ALL(x) x.begin(), x.end()

int main(){

    int n, m, val;
    cin >> n >> m;
    vector<int> row(N,0),col(M,0);    

    FOR(i,0,n{
        FOR(j,0,m){
            cin >> val;
            row[i] += val;
            col[j] += val;
        }
    }        
    
    cout << max(*max_element(ALL(row)),*max_element(ALL(col))) << ENDL;

    return 0;
}
