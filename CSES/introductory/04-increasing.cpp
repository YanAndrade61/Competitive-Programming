#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n; cin >> n;
	ll maxi = -1, moves = 0;
	while(n--){
		ll tmp; cin >> tmp;
		maxi = max(maxi,tmp);
		moves += maxi-tmp;
	}	
	cout << moves << endl;

	return 0;
}
