#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;
map< vector<int> ,int> vcs;

int main(){
    scanf("%d",&t);
    while(t--){
        map<int,bool>mp;
        deque<int> dq;
        scanf("%d",&n);
        int mx=0;
        for(int i=0,tmp;i<n;++i){
            scanf("%d",&tmp);
            if(mp[tmp]==0){
                mp[tmp]=1;
                dq.push_back(tmp);
            }
            else{
                while(dq.front()!=tmp){
                    mp[dq.front()]=0;
                    dq.pop_front();
                }
                dq.pop_front();
                dq.push_back(tmp);
            }
            mx=max(mx,(int)dq.size());
        }
        printf("%d\n",mx);
    }
    return 0;
}
