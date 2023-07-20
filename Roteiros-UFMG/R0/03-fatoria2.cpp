#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{
	int n; cin >> n;
	int fat = 1;
	
	while(n--)
		fat *= n;
	
	cout << fat << ENDL;

	return 0;
}
