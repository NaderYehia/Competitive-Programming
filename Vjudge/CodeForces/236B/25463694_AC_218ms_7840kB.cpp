#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f,M=1<<30;
int t,n,k,a,b,c;
long long d[N];

int main() {
    for(int n=1;n<N;++n){
        for(int i=n;i<N;i+=n){
            ++d[i];
        }
    }
    int ans=0;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            for(int k=1;k<=c;++k){
                ans=ans%M+d[i*j*k];
            }
        }
    }
    printf("%d",ans);
    return 0;
}
