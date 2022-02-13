#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
vector<int> adj[N];
int n,m,u,v;
void DFS(int u){
	vis[u]=1;
	for(int v : adj[u])
		if(!vis[v])
			DFS(v);
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
	int comp=0;
	for(int i=0;i<n;++i){
		if(!vis[i])
		++comp;
		DFS(i);
	}
	if(comp ==1)
		puts("YES");
	else 
		puts("NO");
}