#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

ll f(int h,vector<int> &hs,vector<int> &cs){
    ll cnt=0;
    for(int i=0;i<hs.size();++i){
        cnt+=cs[i]*1ll*abs(hs[i]-h);
    }
    return cnt;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> hs(n);
        for(int i=0;i<n;++i)
            scanf("%d",&hs[i]);
        vector<int> cs(n);
        for(int i=0;i<n;++i)
            scanf("%d",&cs[i]);
        int lo=0,hi=10000;
        while(hi-lo>3){
            int md0=lo+(hi-lo)/3,md1=lo+2*(hi-lo)/3;
            if(f(md0,hs,cs)>f(md1,hs,cs)) lo=md0;
            else hi=md1;
        }
        for(int i=lo;i<=hi;++i){
            if(f(i,hs,cs)<f(lo,hs,cs))
                lo=i;
        }
        printf("%lld\n",f(lo,hs,cs));
    }

    return 0;
}
