#include <bits/stdc++.h>
#define ii pair<int, int>
#define f first
#define s second
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<pair<ii,int>> customers;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        customers.push_back({{a, b},i});
    }

    sort(customers.begin(), customers.end());
    set<ii> st;
    vector<int> rooms(n, 0);
    int maxr = 0, lastr = 0;
    for (int i = 0; i < n; i++) {
        auto it = st.begin();
        if (st.empty() || (*it).f >= customers[i].f.f) {
            lastr++;
            st.insert({customers[i].f.s, lastr});
            rooms[customers[i].s] = lastr;
        }
        else {
            int aux = (*it).s;
            rooms[customers[i].s] = aux;
            st.erase(it);
            st.insert({customers[i].f.s, aux});
        }
        maxr = max(maxr, (int)st.size());
        
    }
    cout << maxr << endl;
    for (auto i : rooms) cout << i << " ";
    cout << endl;

    return 0;
}