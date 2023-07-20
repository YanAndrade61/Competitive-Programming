#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

int main()
{
	int n, r;
	while(cin >> n >> r){
		map<int,int> divers;

		while(r--){
			int v; cin >> v;
			divers[v] = 1;
		}
		
		if(n == r){
			cout << "*" << ENDL;
			continue;
		}
		
		FOR(i,1,n+1){
			if(divers[i] == 0)
				cout << i << " ";
		}
		cout << ENDL;
	}
	

	return 0;
}
