#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

int mem[50][50];

ll nCr(int n,int r){
    if(n==r) return 1;
    if(r>n||r<0) return 0;
    int &ret=mem[n][r];
    if(~ret) return ret;
    return ret=nCr(n-1,r-1)+nCr(n-1,r);
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    memset(mem,-1,sizeof mem);

    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",nCr(n,m-1));
    }


    return 0;
}
