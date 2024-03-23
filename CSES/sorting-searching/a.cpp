#include <bits/stdc++.h>

using namespace std;

int main() {

        vector<int> vec(10,0);

        vec.assign(vec.begin(),vec.end()-5);
        for(auto v: vec) cout << v << " ";
        cout << endl;

        return 0;
}