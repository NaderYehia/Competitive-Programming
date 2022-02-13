#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,cnt;
vector<int> adj[30];
string s;
bool vis[30];

void dfs(int u){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main() {
    scanf("%d\n\n",&t);
    while(t--){
        getline(cin,s);
        n=s[0]-'A';
        for(int i=0;i<30;++i)
            adj[i].clear();
        while(getline(cin,s),s.length()){
            int u=s[0]-'A';
            int v=s[1]-'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(vis,0,sizeof vis);
        int ans=0;
        for(int i=0;i<=n;++i){
            if(!vis[i])
                ++ans,dfs(i);
        }
        printf("%d\n",ans);
        if(t)
            printf("\n");
    }
    return 0;
}
