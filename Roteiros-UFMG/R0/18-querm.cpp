#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++) 

int main()
{
	int n, teste = 1;
	while(cin >> n && n){
		
		cout << "Teste " << teste++ << ENDL;
		FOR(i,1,n+1){
			int x; cin >> x;
			if(x == i) 
				cout << x;
		}
		cout << ENDL << ENDL;
	}

	return 0;
}	
