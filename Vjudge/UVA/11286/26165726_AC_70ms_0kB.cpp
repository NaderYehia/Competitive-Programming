#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;
map< vector<int> ,int> vcs;

int main(){
    while(~scanf("%d",&n),n){
        vcs.clear();
        for(int i=0;i<n;++i){
            vector<int> v;
            for(int j=0,a;j<5;++j){
                cin>>a;
                v.push_back(a);
            }
            sort(v.begin(),v.end());
            vcs[v]++;
        }
        int mx=0;
        for(map< vector<int> ,int>::iterator iter=vcs.begin();iter!=vcs.end();++iter){
            mx=max(mx,iter->second);
        }
        int cnt=0;
        for(map< vector<int> ,int>::iterator iter=vcs.begin();iter!=vcs.end();++iter){
            if(iter->second==mx)
                ++cnt;
        }
        printf("%d\n",cnt*mx);
    }
    return 0;
}
