#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
   
    vector<pair<int,char>> vec(26);
    string line; cin >> line;
    for(auto c: line) {
        vec[c-'A'].f--;
        vec[c-'A'].s = c;
    }
    
    int l = 0, r = 1;
    string ans = "";
    while(1) {
        sort(vec.begin(), vec.end());
        if(vec[l].f < 0 && vec[r].f < 0) {
            ans += vec[l].s;
            ans += vec[r].s;
            vec[l].f++;
            vec[r].f++;
        } else {
            break;
        }
    }
    cout << ans.size()/2 << endl;
    for (int i = 0; i < ans.size(); i+=2) {
        cout << ans[i] << ans[i+1] << endl;
    }
    

    return 0;
}