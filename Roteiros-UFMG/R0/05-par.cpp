#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{
	int n, teste = 1;
	string player[2];

	while(cin >> n && n){
		
		cin >> player[0] >> player[1];
		cout << "Teste " << teste++ << ENDL;
		while(n--){
			int a, b; cin >> a >> b;
			cout << player[(a+b)&1] << ENDL;
		}
		cout << ENDL;
	}

	return 0;
}
