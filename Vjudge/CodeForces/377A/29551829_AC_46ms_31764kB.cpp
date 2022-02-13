#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=1e9+7,OO=0x3f3f3f3f;

int n,m,k;
char grid[N][N];
bool vis[N][N];

int to_dfs;

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<m&&grid[r][c]!='#';
}

void dfs(int r,int c){
    if(to_dfs==0) return;
    --to_dfs;
    vis[r][c]=1;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(abs(i)==abs(j)) continue;
            if(valid(r+i,c+j)&&!vis[r+i][c+j]){
                dfs(r+i,c+j);
            }
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<n;++i)
        scanf("%s",grid[i]);



    int dots=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(grid[i][j]=='.') ++dots;

    to_dfs=dots-k;

    for(int i=0;i<n&&to_dfs;++i)
        for(int j=0;j<m&&to_dfs;++j)
            if(grid[i][j]=='.') dfs(i,j);

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!vis[i][j]&&grid[i][j]=='.') grid[i][j]='X';

    for(int i=0;i<n;++i)
        printf("%s\n",grid[i]);

    return 0;
}
