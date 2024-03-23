#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

        int n; cin >> n;
        if(n == 3 || n == 2){
		cout << "NO SOLUTION" << endl; 
		return 0;
	}
	if(n == 4) {
		cout << "3 1 4 2" << endl; 
        	return 0;
	}
	cout << "1" << endl;
        for (int i = 3; i <= n; i +=2) cout << " " << i;
        for (int i = 2; i <= n; i += 2) cout << " " << i;
        cout << endl;

        return 0;
}
