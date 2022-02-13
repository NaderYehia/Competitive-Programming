#include<bits/stdc++.h>
using namespace std;
const int N= 2e2+5;
vector<int>adj[N];
int n,m,u,v,t,a;
bool vis[N],col[N],isBi;
void DFS(int u){
	vis[u]=1;
	for(int v: adj[u]){
		if(!vis[v]){
			col[v]= !col[u];
			DFS(v);
		}
		else if(col[v]==col[u])
			isBi=0;
	}
}
int main(){
		while(1){
		scanf("%d",&n);
		if(n==0)
			return 0;
		scanf("%d",&m);
		memset(vis,0,sizeof vis);
		memset(col,0,sizeof col);
		isBi=1;	
		for(int i=0;i<n;++i)
			adj[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d %d",&u,&v);
			--u,--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0;i<n;++i){
			if(!vis[i]){
				col[i]=1;
				DFS(i);
			}
		}
		if(isBi)
			puts("BICOLORABLE.");
		else 
			puts("NOT BICOLORABLE.");
		}
	
}