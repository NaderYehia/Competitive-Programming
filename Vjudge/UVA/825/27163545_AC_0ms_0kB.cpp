#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e6+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
int grid[105][105];
int mem[105][105];

bool valid(int r,int c){
    return r<n&&c<m&&grid[r][c]!=-1;
}

int solve(int r,int c){
    if(r==n-1&&c==m-1) return 1;
    int &ret=mem[r][c];
    if(~ret) return mem[r][c];
    ret=0;
    if(valid(r+1,c)) ret+=solve(r+1,c);
    if(valid(r,c+1)) ret+=solve(r,c+1);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        getchar();
        memset(grid,0,sizeof grid);
        for(int i=0;i<n;++i){
            string s;
            getline(cin,s);
            stringstream ss(s);
            int x,y;
            ss>>x;
            while(ss>>y)
                grid[x-1][y-1]=-1;
        }
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
        if(t) printf("\n");
    }
    return 0;
}
