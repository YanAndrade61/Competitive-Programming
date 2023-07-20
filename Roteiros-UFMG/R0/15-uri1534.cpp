#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

int main()
{

	int n;
	while(cin >> n){

		FOR(i,0,n){
			FOR(j,0,n){
				if(i == j) cout << "1";
				else if( i + j + 1 == n) cout << "2";
				else cout << "3";
			}
			cout << ENDL;
		}

	}

	return 0;
}
