#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

int arr[N];
int cnt[105];

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t,tc=1;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        memset(cnt,0,sizeof cnt);
        arr[1]=1,arr[2]=2,arr[3]=3;
        for(int i=4;i<=n;++i)
            arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%m+1;
        arr[n+1]=k+1;

        int i=1,j=2,seg=OO,rem=k-2;
        cnt[1]=1,cnt[2]=1;
        while(j<=n){
            while(arr[i]>k) ++i;
            if(rem<=0) seg=min(seg,j-i+1);
            if(cnt[arr[i]]>1){
                --cnt[arr[i]];
                ++i;
                continue;
            }
            if(arr[j+1]>k){
                ++j;
                continue;
            }
            if(cnt[arr[j+1]]==0) --rem;
            cnt[arr[j+1]]++;
            ++j;
        }
        if(seg==OO) printf("Case %d: sequence nai\n",tc++);
        else printf("Case %d: %d\n",tc++,seg);

    }

    return 0;
}
