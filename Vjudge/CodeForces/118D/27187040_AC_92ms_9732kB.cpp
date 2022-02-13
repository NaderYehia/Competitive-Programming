#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e8,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int n1,n2,k1,k2;
int mem[105][105][15][15];

int solve(int ln1,int ln2,int lk1,int lk2){
    if(ln1==0&&ln2==0) return 1;
    int &ret=mem[ln1][ln2][lk1][lk2];
    if(~ret) return ret;
    ret=0;
    if(ln1&&lk1) ret=(ret%M+solve(ln1-1,ln2,lk1-1,k2)%M)%M;
    if(ln2&&lk2) ret=(ret%M+solve(ln1,ln2-1,k1,lk2-1)%M)%M;
    return ret;
}


int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(n1,n2,k1,k2));
    return 0;
}
