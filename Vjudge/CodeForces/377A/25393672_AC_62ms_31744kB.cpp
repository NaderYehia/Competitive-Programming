#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,cnt;
char grid[505][505];
bool vis[505][505];

bool valid(int x,int y){
    return x>-1&&x<n&&y>-1&&y<m&&grid[x][y]!='#';
}

void dfs(int u,int v){
    if(cnt==0)
        return;
    --cnt;
    vis[u][v]=1;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(abs(i)==abs(j))continue;
            if(valid(u+i,v+j)&&grid[u+i][v+j]=='.'&&!vis[u+i][v+j])
                dfs(u+i,v+j);
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    cnt=0;
    for(int i=0;i<n;++i){
        scanf("%s",grid[i]);
        for(int j=0;j<m;++j)
            if(grid[i][j]=='.')
                ++cnt;
    }
    cnt-=k;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='.')
                dfs(i,j);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j]&&grid[i][j]=='.')
                grid[i][j]='X';
        }
    }
    for(int i=0;i<n;++i)
        printf("%s\n",grid[i]);
    return 0;
}
