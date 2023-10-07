#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int maxc = 0, tmp = 0;
	string dna; cin >> dna;
	char atual = dna[0];
	for(char c: dna){
		if(atual != c){
			tmp = 0;
			atual = c;
		}
		tmp++;
		maxc = max(maxc,tmp);
	}
	cout << maxc << endl;

	return 0;
}
