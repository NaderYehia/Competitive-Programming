#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
int mem[N][N];
double d;

int solve(int i,int spc){
    if(i==n) return 0;
    int &ret=mem[i][spc];
    if(~ret) return ret;
    if(arr[i]==spc) return solve(i+1,spc);
    if(arr[i]>spc)
        ret=min(solve(i+1,arr[i]),1+solve(i+1,spc));
    else
        ret=1+solve(i+1,spc);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%f",arr+i,&d);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0,1));
    return 0;
}
