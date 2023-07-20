#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{
	int n; cin >> n;
	int soma = 0;

	while(n--){
		int x; cin >> x;
		soma += x;
	}

	cout << soma << ENDL;

	return 0;
}
