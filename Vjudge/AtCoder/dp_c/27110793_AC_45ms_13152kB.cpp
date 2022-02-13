#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n,m,a[N],b[N],c[N];
int mem[N][5];

int solve(int i=0,int bk=0){
    if(i==n) return 0;
    int &ret=mem[i][bk];
    if(~ret) return ret;
    if(bk!=1)
        ret=max(ret,solve(i+1,1)+a[i]);
    if(bk!=2)
        ret=max(ret,solve(i+1,2)+b[i]);
    if(bk!=3)
        ret=max(ret,solve(i+1,3)+c[i]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d%d",a+i,b+i,c+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve());
    return 0;
}
