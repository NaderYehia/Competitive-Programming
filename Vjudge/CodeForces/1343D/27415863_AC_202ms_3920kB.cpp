#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int frq[2*k+5];
        int cnt[2*k+5];
        memset(frq,0,sizeof frq);
        memset(cnt,0,sizeof cnt);
        for(int i=0,j=n-1;i<j;++i,--j){
            ++frq[arr[i]+arr[j]];
            cnt[min(arr[i],arr[j])+1]+=1;
            cnt[max(arr[i],arr[j])+k+1]-=1;
        }
        for(int i=1;i<=2*k;++i)
            cnt[i]+=cnt[i-1];
        int ans=1e9;
        for(int i=2;i<=2*k;++i){
            ans=min(ans,cnt[i]-frq[i]+(n/2-cnt[i])*2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
