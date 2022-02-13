#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;

int power(int x,int p){
    int ret=1;
    while(p){
        if(p&1) ret=(ret*1ll*x)%M;
        x=(x*1ll*x)%M;
        p>>=1;
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,k;
    while(~scanf("%d%d",&n,&k),n||k){
        int ans=((2*power(n-1,n-1))%M+(2*power(n-1,k))%M)%M;
        ans=(ans+(power(n,k)+power(n,n))%M)%M;
        printf("%d\n",ans);
    }

    return 0;
}
