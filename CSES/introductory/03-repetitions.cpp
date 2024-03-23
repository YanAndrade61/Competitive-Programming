#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int maxc = 0, tmp = 0;
	char ant = ' ', atual;
	while(cin >> atual){
		if(atual != ant){
			tmp = 0;
			ant = atual;
		}
		tmp++;
		maxc = max(maxc,tmp);
	}
	cout << maxc << endl;

	return 0;
}
