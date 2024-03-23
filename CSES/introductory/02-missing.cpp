#include<bits/stdc++.h>

using namespace std;

int main(){

	long long n; cin >> n;
	long long sum=(n*(n+1))/2;
	while(n-- && n){
		int tmp; cin >> tmp;
		sum -= tmp;
	}
	cout << sum << endl;
	
	return 0;
}
