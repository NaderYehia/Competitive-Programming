#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
ll a[N];
ll mem[2][N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",a+i),a[i]+=a[i-1];
    mem[0][1]=0;
    for(int i=1;i<=k;++i){
        for(int j=i*m;j<=n;++j){
            mem[1][j]=max(mem[1][j-1],mem[0][j-m]+a[j]-a[j-m]);
        }
        for(int j=1;j<=n;++j)
            mem[0][j]=mem[1][j];
    }
    printf("%lld",mem[0][n]);
    return 0;
}
