#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
char s[5];
vector<int> adj[30];
bool vis[30];
vector<int>ans;
set<int> se;

void print(int from,int to){
    int idx;
    for(int i=0;i<ans.size();++i){
        if(ans[i]==to)
            idx=i;
    }
    for(int i=idx;i<ans.size();++i)
        se.insert(ans[i]);
}

void dfs(int u,int par){
    vis[u]=1;
    for(int i=0,v;i<adj[u].size();++i){
        v=adj[u][i];
        if(!vis[v]) ans.push_back(v),dfs(v,u),ans.pop_back();
        else print(u,v);
    }
}

int main() {
    while(~scanf("%s",&s)){
        int u=s[0]-'A';
        int v=s[2]-'A';
        adj[u].push_back(v);
    }
    for(int i=0;i<26;++i){
        if(!vis[i]&&adj[i].size())
            ans.push_back(i),dfs(i,-1),ans.pop_back();
    }
    for(int val:se)
        printf("%c",(char)val+'A');
    return 0;
}
