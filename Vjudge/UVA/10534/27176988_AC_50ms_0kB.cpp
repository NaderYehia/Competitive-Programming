#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int a[N],incr[N],decr[N],tmp[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        memset(tmp,OO,sizeof tmp);
        for(int i=0;i<n;++i){
            int idx=lower_bound(tmp,tmp+n,a[i])-tmp;
            tmp[idx]=min(tmp[idx],a[i]);
            incr[i]=idx+1;
        }
        memset(tmp,OO,sizeof tmp);
        for(int i=n-1;i>-1;--i){
            int idx=lower_bound(tmp,tmp+n,a[i])-tmp;
            tmp[idx]=min(tmp[idx],a[i]);
            decr[i]=idx+1;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,min(incr[i],decr[i])+min(incr[i],decr[i])-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
