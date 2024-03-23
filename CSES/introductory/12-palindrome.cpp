#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main(){

        string str; cin >> str;
        map<char,int> freq;
        for(auto c: str) freq[c]++;

        int oddn = 0;
        string ans = "", oddc="";
        for (auto& p: freq){
                if(p.s&1) {
                        oddc += p.f;
                        oddn++;
                        p.s--;
                }
                for(int i = 0; i < p.s/2; i++) ans += p.f;
        }
        if(oddn > 1) 
                cout << "NO SOLUTION" << endl;
        else {
                string rans(ans.rbegin(),ans.rend());
                cout << ans << oddc << rans << endl;
        }
        return 0;
}