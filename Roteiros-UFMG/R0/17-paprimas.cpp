#include <bits/stdc++.h>

using namespace std;

#define ENDL '\n'

int char2dec(char c){

    if(c > 'Z')
        return c - 96;
    return c - 65 + 27;
}

int main(){

    string word;
    int n;
    bool prime;

    while (cin >> word){
        
        n= 0;
        for(char c: palavra)
            n += char2dec(c);

        prime = true;
        for (int i = 2; i*i <= n; i++){
            if(n%i == 0)
                prime = false;
        }

        prime ? cout << "It is a prime word." : cout << "It is not a prime word."; 
    	cout << ENDL;
    }
    return 0;
}
