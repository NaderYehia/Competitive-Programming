#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k,tot;
int c,n1,n2,n3;
int mem[205][105][55];

int solve(int remc,int remn2,int remn3){
    if(remc==0) return 0;
    int &ret=mem[remc][remn2][remn3];
    if(~ret) return ret;
    ret=OO;
    int remn1=tot-(c-remc)*8-remn2*5-remn3*10;
    if(remn3-1>=0) ret=min(ret,1+solve(remc-1,remn2,remn3-1));
    if(remn2-2>=0) ret=min(ret,2+solve(remc-1,remn2-2,remn3));
    if(remn1-8>=0) ret=min(ret,8+solve(remc-1,remn2,remn3));
    if(remn2-1>=0&&remn1-3>=0) ret=min(ret,4+solve(remc-1,remn2-1,remn3));
    if(remn3-1>=0&&remn1-3>=0) ret=min(ret,4+solve(remc-1,remn2+1,remn3-1));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    memset(mem,-1,sizeof mem);
    while(t--){
        scanf("%d%d%d%d",&c,&n1,&n2,&n3);
        tot=n1+n2*5+n3*10;
        printf("%d\n",solve(c,n2,n3));
    }
    return 0;
}
