#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
vector<int>adj[N];
map<string,int>mp;
bool vis[N];
int n,m,t,mx=0,c=0;
string u,v;
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
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			return 0;
		mx=0,c=0;
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;++i)
			adj[i].clear();
		for(int i=0;i<n;++i){
			cin>>u;
			mp[u]=i;
		}
		for(int i=0;i<m;++i){
			cin>>u>>v;
			adj[mp[u]].push_back(mp[v]);
			adj[mp[v]].push_back(mp[u]);
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