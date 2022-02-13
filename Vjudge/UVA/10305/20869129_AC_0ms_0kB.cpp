#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
bool vis[N];
vector<int>adj[N];
int n,m,u,v;
void DFS(int u){
	vis[u]=1;
	for(int v:adj[u])
		if(!vis[v])
			DFS(v);
		printf("%d ",u);
}
int main(){
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			return 0;
		for(int i=0;i<n;++i)
			adj[i].clear();
		memset(vis,0,sizeof vis);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			adj[v].push_back(u);
		}
		for(int i=1;i<n+1;++i)
			if(!vis[i])
				DFS(i);
		puts("");
	}

}