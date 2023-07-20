#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define ll long long

int main()
{
	ll n; cin >> n;
	n = abs(n);

	bool primo = true;

	for(ll i = 2; i*i <= n; i++)
		if(n % i == 0) primo = false;
	
	primo ? cout << "sim" : cout << "nao";
	cout << ENDL;

	return 0;
}
