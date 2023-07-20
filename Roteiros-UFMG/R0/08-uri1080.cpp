#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

int main()
{
	int n, maxi = -1, posi;
	
	FOR(i,1,101){
		cin >> n;
		if(maxi < n){
			maxi = n;
			posi = i;
		}
	}
	cout << maxi << ENDL;
	cout << posi << ENDL;

	return 0;
}
