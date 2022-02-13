#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;

int main(){
    while(~scanf("%d",&n),n){
        long long ans=0;
        map<int,int> mp;
        set<int> st;
        for(int i=0;i<n;++i){
            scanf("%d",&k);
            for(int j=0,tmp;j<k;++j){
                scanf("%d",&tmp);
                st.insert(tmp);
                mp[tmp]++;
            }
            set<int>::iterator iter=st.end();--iter;
            int l=(*st.begin()),r=(*iter);
            ans+=r-l;
            --mp[l],--mp[r];
            if(mp[l]==0)
                st.erase(l);
            if(mp[r]==0)
                st.erase(r);
        }
        cout<<ans<<endl;
    }
    return 0;
}
