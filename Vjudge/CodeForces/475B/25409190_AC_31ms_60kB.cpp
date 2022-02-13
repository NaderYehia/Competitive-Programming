#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n,m,q;
char ew[30][30];
char sn[30][30];
int vis[30][30];

bool valid(int u,int v){
    return u>-1&&v>-1&&u<n&&v<m;
}

void dfs(int u,int v){
    vis[u][v]=1;
    if(valid(u-1,v)&&!vis[u-1][v]&&sn[u][v]=='u'){
        dfs(u-1,v);
    }
    if(valid(u+1,v)&&!vis[u+1][v]&&sn[u][v]=='d'){
        dfs(u+1,v);
    }
    if(valid(u,v+1)&&!vis[u][v+1]&&ew[u][v]=='r'){
        dfs(u,v+1);
    }
    if(valid(u,v-1)&&!vis[u][v-1]&&ew[u][v]=='l'){
        dfs(u,v-1);
    }
}

bool allvis(){
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!vis[i][j])
                return 0;
    return 1;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        char c;
        cin>>c;
        if(c=='<')
            for(int j=0;j<m;++j)
                ew[i][j]='l';
        else
            for(int j=0;j<m;++j)
                ew[i][j]='r';
    }
    for(int i=0;i<m;++i){
        char c;
        cin>>c;
        if(c=='v')
            for(int j=0;j<n;++j)
                sn[j][i]='d';
        else
            for(int j=0;j<n;++j)
                sn[j][i]='u';
    }
    bool no=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            memset(vis,0,sizeof vis);
            dfs(i,j);
            if(!allvis())
                no=1;
        }
    }
    if(no)
        printf("NO");
    else
        printf("YES");
    return 0;
}
