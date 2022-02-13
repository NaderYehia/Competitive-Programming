#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=2<<30,OO=0x3f3f3f3f;
int t,n,m,k,a,b,c;
int divs[N];

void sieve(){
    for(int i=1;i<N;++i)
        for(int j=i;j<N;j+=i)
            ++divs[j];
}

int main(){
    //freopen("myfile.txt","w",stdout);
    sieve();
    scanf("%d%d%d",&a,&b,&c);
    int cnt=0;
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            for(int k=1;k<=c;++k){
                cnt=(cnt%M+divs[i*j*k]%M)%M;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
