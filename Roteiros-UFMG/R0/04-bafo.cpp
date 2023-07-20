#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{
	int n, test = 1; 
	
	while(cin >>n && n){

		int dif = 0;
		while(n--){
			int a, b; cin >> a >> b;
			dif += a - b;
		}
		
		cout << "Teste " << test++ << ENDL;
		dif > 0 ? cout << "Aldo" : cout << "Beto";
		cout << ENDL << ENDL;

	}

	return 0;
}
