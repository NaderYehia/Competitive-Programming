#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool vis[N];
int n,m,u,v;
bool hasCycle;
void DFS(int u,int p){
	vis[u]=1;
	for(int v : adj[u]){
		if(v==p)	
			continue;
		if(vis[v])
			hasCycle=1;
		else
			DFS(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if(n-1!=m){
		puts("NO");
		return 0;
	}
	for(int i=0;i<m;++i){
		scanf("%d %d",&u,&v);
		--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;++i){
		if(!vis[i])
			DFS(i,-1);
	}
	if(!hasCycle)
		puts("YES");
	else 
		puts("NO");
}