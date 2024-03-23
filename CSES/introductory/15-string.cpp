#include <bits/stdc++.h>
#define s second
using namespace std;

int main() {

        string str = "";
        map<char,int> freq;
        char c;
        while(cin >> c){
                str += c;
                freq[c]++;
        }       
        
        int fat[] = {1,1,2,6,24,120,720,5040,40320};
        int count = fat[str.size()];
        for(auto p: freq) count /= fat[p.s];
        cout << count << endl;
        
        sort(str.begin(), str.end());
        do {
                cout << str << endl;
        } while(next_permutation(str.begin(), str.end()));
}