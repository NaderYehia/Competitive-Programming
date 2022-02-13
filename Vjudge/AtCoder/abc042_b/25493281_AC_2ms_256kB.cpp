#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
vector<string>v;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
        cout<<v[i];
    return 0;
}
