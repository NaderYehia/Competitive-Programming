#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
string s;


int main() {
    cin>>s;
    for(int i=0;i<s.length()-1;++i){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2;
            return 0;
        }
        if(i+2<s.length()&&s[i]==s[i+2]){
            cout<<i+1<<" "<<i+3;
            return 0;
        }
    }
    cout<<-1<<" "<<-1;
    return 0;
}
