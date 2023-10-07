#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n; cin >> n;
	cout << n;
	while(n > 1){
		n = n&1 ? n*3 + 1 : n/2;
		cout << " " << n;
	}
	cout << endl;


	return 0;
}
