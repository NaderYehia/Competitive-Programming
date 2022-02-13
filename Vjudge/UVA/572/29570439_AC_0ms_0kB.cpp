#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

int n,m;
char grid[N][N];
int vis[N][N],vid;

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<m;
}

void dfs(int r,int c){
    vis[r][c]=vid;
    for(int i=-1;i<2;++i){
        for(int j=-1;j<2;++j){
            if(valid(r+i,c+j)&&vis[r+i][c+j]!=vid&&grid[r+i][c+j]=='@'){
                dfs(r+i,c+j);
            }
        }
    }
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(scanf("%d%d",&n,&m),n){
        for(int i=0;i<n;++i)
            scanf("%s",grid[i]);

        ++vid;
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='@'&&vis[i][j]!=vid){
                    dfs(i,j);
                    ++cnt;
                }
            }
        }
        printf("%d\n",cnt);
    }


    return 0;
}
