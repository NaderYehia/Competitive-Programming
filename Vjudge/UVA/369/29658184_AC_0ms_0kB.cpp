#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

ll mem[110][110];

ll nCr(int n,int r){
    if(n==r) return 1;
    if(r>n||r<0) return 0;
    ll &ret=mem[n][r];
    if(~ret) return ret;
    return ret=nCr(n-1,r-1)+nCr(n-1,r);
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    memset(mem,-1,sizeof mem);


    int n,m;
    while(~scanf("%d%d",&n,&m),n||m){
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,nCr(n,m));
    }


    return 0;
}
