#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int main()
{
	int n, p ,q;
	char op; 
	cin >> n;
	cin >> p >> op >> q;

	bool overflow = false;

	if(op == '+' && p+q > n) overflow = true;
	if(op == '*' && p*q > n) overflow = true;
	
	overflow ? cout << "OVERFLOW" : cout << "OK";
	cout << ENDL;

	return 0;
}
