#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

int n,m;
char grid[N][N];
bool vis[N][N];

void dfs(int r,int c){
    vis[r][c]=1;
    if(r+1<n&&grid[r+1][c]=='.'){
        grid[r+1][c]='V';
        dfs(r+1,c);
    }
    else if(r+1<n&&grid[r+1][c]=='#'){
        if(c+1<m&&grid[r][c+1]=='.'){
            grid[r][c+1]='V';
            dfs(r,c+1);
        }
        if(c-1>-1&&grid[r][c-1]=='.'){
            grid[r][c-1]='V';
            dfs(r,c-1);
        }
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    scanf("%d%d",&n,&m);

    for(int i=0;i<n;++i)
        scanf("%s",grid[i]);

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='V'&&!vis[i][j]){
                dfs(i,j);
            }
        }
    }

    for(int i=0;i<n;++i)
        printf("%s\n",grid[i]);

    return 0;
}
