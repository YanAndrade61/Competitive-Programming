#include <bits/stdc++.h>

using namespace std;

int main() {

        int n; cin >> n;
        vector<int> musics(n);
        map<int,int> idx;
        for (int i = 0; i < n; i++) {
                cin >> musics[i];
                idx[musics[i]] = -1;
        }
        
        int start = 0, ans = 0;
        for (int j = 0; j < n; j++) {

                start = max(start, idx[musics[j]] +1);
                ans = max(ans,j-start+1);
                idx[musics[j]] = j;
        }

        cout << ans << endl;

        return 0;
}