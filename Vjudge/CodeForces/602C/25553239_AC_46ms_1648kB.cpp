#include<bits/stdc++.h>

using namespace std;

const int N=4e2+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
vector<int> train[N];
vector<int> bus[N];
bool vis[N];
int dis[N];

int bfsBus(){
    memset(dis,-1,sizeof dis);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(q.size()){
        int u=q.front();
        if(u==n-1)
            return dis[u];
        q.pop();
        for(int i=0,v;i<bus[u].size();++i){
            v=bus[u][i];
            if(dis[v]==-1) dis[v]=dis[u]+1,q.push(v);
        }
    }
    return -1;
}

int bfsTrain(){
    memset(dis,-1,sizeof dis);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(q.size()){
        int u=q.front();
        if(u==n-1)
            return dis[u];
        q.pop();
        for(int v : train[u]){
            if(dis[v]==-1) dis[v]=dis[u]+1,q.push(v);
        }
    }
    return -1;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;++i){
        scanf("%d%d",&u,&v);
        --u,--v;
        train[u].push_back(v);
        train[v].push_back(u);
    }
    for(int i=0;i<n;++i){
        memset(vis,0,sizeof vis);
        for(int j : train[i])
            vis[j]=1;
        for(int j=0;j<n;++j)
            if(!vis[j])
                bus[i].push_back(j);
    }
    for(int val:train[0]){
        if(val==n-1){
            printf("%d",bfsBus());
            return 0;
        }
    }
    printf("%d",bfsTrain());
    return 0;
}
