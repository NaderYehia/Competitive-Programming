#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
vector<int>adj[N];
bool vis[N];
int n,m,u,v,t,mx=0,c=0;
void DFS(int u){
	vis[u]=1;
	for(int v:adj[u]){
		if(!vis[v]){
			++c;
			DFS(v);
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		mx=0,c=0;
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;++i)
			adj[i].clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			--u,--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0;i<n;++i){
			if(!vis[i]){
				mx=max(c,mx);
				c=0;
				DFS(i);
			}
		}
		mx=max(c,mx);
		printf("%d\n",mx+1);
	}
}