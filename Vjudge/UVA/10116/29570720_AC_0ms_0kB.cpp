#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

int n,m,k,cnt;
char grid[N][N];
int vis[N][N],vid;

int loop,loopR,loopC;

bool out(int r,int c){
    return r<0||c<0||r>=n||c>=m;
}

void dfs(int r,int c){
    if(out(r,c)) return;
    if(vis[r][c]==vid){
        loop=1;
        loopR=r;
        loopC=c;
        return;
    }
    vis[r][c]=vid;
    if(grid[r][c]=='W'){
        dfs(r,c-1);
        ++cnt;
    }
    else if(grid[r][c]=='E'){
        dfs(r,c+1);
        ++cnt;
    }
    else if(grid[r][c]=='N'){
        dfs(r-1,c);
        ++cnt;
    }
    else{
        dfs(r+1,c);
        ++cnt;
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%d%d%d",&n,&m,&k),n||m||k){
        for(int i=0;i<n;++i)
            scanf("%s",grid[i]);

        ++vid,cnt=0,loop=0;
        dfs(0,k-1);
        if(loop){
            ++vid,cnt=0;
            dfs(loopR,loopC);
            int loopCnt=cnt;
            cnt=0;
            dfs(0,k-1);
            printf("%d step(s) before a loop of %d step(s)\n",cnt,loopCnt);
        }
        else{
            printf("%d step(s) to exit\n",cnt);
        }
    }


    return 0;
}
