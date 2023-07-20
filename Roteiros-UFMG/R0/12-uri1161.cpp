#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ll long long

int main()
{
	/*Os fatorais ficam pre-computados*/
	vector<ll> fat(21,1);
	FOR(i,1,21)
		fat[i] *= fat[i-1]; 
	
	int m, n;
	while(cin >> m >> n){
		ll ans = fat[m] + fat[n];
		cout << ans << ENDL;
	}

	return 0;
}
