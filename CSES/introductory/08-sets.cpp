#include<bits/stdc++.h>

using namespace std;
 
int main(){
 
	int n; cin >> n;
	if((n*(n+1)/2)&1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    int impar = n&1;
    int lim = impar ? n-1 : n; 
    //Set 1
    cout << ceil(n/2.0) << endl;
    for (int i = 1; i <= lim/2; i+=2) {
        if(i > 1) cout << " ";
        cout << i << " " << lim-i+1;
    }
    cout << endl;
    //Set 2
    cout << (n&1 ? ceil(n/2.0)-1 : ceil(n/2.0)) << endl;
	for (int i = 2; i <= lim/2; i+=2) {
        if(i > 2) cout << " ";
        cout << i << " " << lim-i+1;
    }
    if(impar) cout << " " << n;
    cout << endl;
		
	return 0;
}