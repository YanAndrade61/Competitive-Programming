#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{

	int n, teste = 1;

	while(cin >> n){
		int acc = 0, ans = INT_MAX;
		while(n--){
			int a; cin >> a;
			if(a == acc && ans == INT_MAX) ans = a;
			acc += a;
		}
		cout << "Instacia " << teste++ << ENDL;
		ans != INT_MAX ? cout << ans : cout << "nao achei";
		cout << ENDL;
	}

	return 0;
}
