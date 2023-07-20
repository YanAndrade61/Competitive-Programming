#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{

	int q, d, p;

	while(cin >> q >> d >> p && q){
		
		int pag = (int)abs(( q * d * p) / ( p - q ));
		
		cout << pag;
		pag > 1 ? cout << " paginas" : cout << " pagina";
		cout << ENDL;
	}

	return 0;
}

