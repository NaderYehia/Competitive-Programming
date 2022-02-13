#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,r,c,n,m,k,w;
char grid[105][105];
bool vis[105][105];
int even,odd;

bool valid(int u,int v){
    return u>-1&&v>-1&&u<r&&v<c&&grid[u][v]!='w';
}

void dfs(int u,int v){
    vis[u][v]=1;
    set<pair<int,int> > cnt;
    if(valid(u+n,v+m)){
        cnt.insert({u+n,v+m});
        if(!vis[u+n][v+m]) dfs(u+n,v+m);
    }
    if(valid(u+n,v-m)){
        cnt.insert({u+n,v-m});
        if(!vis[u+n][v-m]) dfs(u+n,v-m);
    }
    if(valid(u-n,v+m)){
        cnt.insert({u-n,v+m});
        if(!vis[u-n][v+m]) dfs(u-n,v+m);
    }
    if(valid(u-n,v-m)){
        cnt.insert({u-n,v-m});
        if(!vis[u-n][v-m]) dfs(u-n,v-m);
    }
    if(valid(u+m,v+n)){
        cnt.insert({u+m,v+n});
        if(!vis[u+m][v+n]) dfs(u+m,v+n);
    }
    if(valid(u+m,v-n)){
        cnt.insert({u+m,v-n});
        if(!vis[u+m][v-n]) dfs(u+m,v-n);
    }
    if(valid(u-m,v+n)){
        cnt.insert({u-m,v+n});
        if(!vis[u-m][v+n]) dfs(u-m,v+n);
    }
    if(valid(u-m,v-n)){
        cnt.insert({u-m,v-n});
        if(!vis[u-m][v-n]) dfs(u-m,v-n);
    }
    if(cnt.size()&1) ++odd;
    else ++even;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&r,&c,&n,&m,&w);
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                grid[i][j]='.';
        for(int i=0,u,v;i<w;++i){
            scanf("%d%d",&u,&v);
            grid[u][v]='w';
        }
        even=odd=0;
        memset(vis,0,sizeof vis);
        dfs(0,0);
        printf("Case %d: %d %d\n",tc++,even,odd);
    }
    return 0;
}
