#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
ll arr[N];
ll mem[N][N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",arr+i),arr[i]+=arr[i-1];
    for(int i=1;i<=k;++i){
        for(int j=i*m;j<=n;++j){
            mem[j][i]=max(mem[j-1][i],mem[j-m][i-1]+arr[j]-arr[j-m]);
        }
    }
    printf("%lld",mem[n][k]);
    return 0;
}
