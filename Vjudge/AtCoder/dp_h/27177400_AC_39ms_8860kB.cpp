#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
char grid[N][N];
int mem[N][N];

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<m&&grid[r][c]!='#';
}

int solve(int i=0,int j=0){
    if(i==n-1&&j==m-1) return 1;
    int &ret=mem[i][j];
    if(~ret) return ret;
    ret=0;
    if(valid(i+1,j)) ret=(ret%M+solve(i+1,j)%M)%M;
    if(valid(i,j+1)) ret=(ret%M+solve(i,j+1)%M)%M;
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s",grid+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve());
    return 0;
}
