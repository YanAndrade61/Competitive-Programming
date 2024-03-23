#include <bits/stdc++.h>

using namespace std;

int main() {

        int n; cin >> n;
        vector<pair<int,int>> movies;
        while(n--) {
                int a,b; cin >> a >> b;
                movies.push_back({b,a});
        }       
        sort(movies.begin(), movies.end());
        
        int ans = 0;
        int atual = 0;
        for(auto m: movies) {
                if(m.second >= atual) {
                        ans++;
                        atual = m.first;
                }
        }
        cout << ans << endl;
        return 0;
}