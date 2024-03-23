#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m; cin >> n >> m;

    vector<int> idx(n+2,0), nums(n+1,0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        idx[x] = i;
        nums[i] = x;
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans += (idx[i] < idx[i-1]);
    }

    while(m--) {
        int a,b; cin >> a >> b;
        int val1 = nums[a], val2 = nums[b];
        swap(nums[a], nums[b]);
        
        if(idx[val1-1] <=  idx[val1] && idx[val1-1] > b) ans++;
        if(idx[val1-1] >  idx[val1] && idx[val1-1] <= b) ans--; 
        if(idx[val1] <=  idx[val1+1] && idx[val1+1] < b) ans++;
        if(idx[val1] >  idx[val1+1] && idx[val1+1] >= b) ans--; 
        idx[val1] = b;

        if(idx[val2-1] <=  idx[val2] && idx[val2-1] > a) ans++;
        if(idx[val2-1] >  idx[val2] && idx[val2-1] <= a) ans--; 
        if(idx[val2] <=  idx[val2+1] && idx[val2+1] < a) ans++;
        if(idx[val2] >  idx[val2+1] && idx[val2+1] >= a) ans--; 
        idx[val2] = a;
        
        cout << ans << endl;
    }


    return 0;
}