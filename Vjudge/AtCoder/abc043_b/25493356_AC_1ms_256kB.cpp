#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
string s;
vector<char>v;

int main() {
    cin>>s;
    for(int i=0;s[i];++i){
        if(s[i]=='0')
            v.push_back(s[i]);
        else if(s[i]=='1')
            v.push_back(s[i]);
        else if(v.size())
            v.pop_back();
    }
    for(int i=0;i<v.size();++i)
        cout<<v[i];
    return 0;
}
