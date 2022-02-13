#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

vector<int> adj[N];
int col[N],U[N],V[N];
bool vis[N];

bool can(int u,int c){
	vis[u]=1;
	bool ret=(col[u]==c);
	for(int i=0;i<adj[u].size();++i){
		int v=adj[u][i];
		if(!vis[v]) ret&=can(v,c);
	}
	return ret;
}


int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		--u,--v;
		U[i]=u,V[i]=v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;++i)
		scanf("%d",col+i);
	
	int idx=-1;
	for(int i=0;i<n-1;++i){
		if(col[U[i]]!=col[V[i]]){
			idx=i;
		}
	}
	if(idx==-1){
		printf("YES\n1\n");
	}
	else{
		vis[U[idx]]=1;
		bool succ=1;
		for(int i=0;i<adj[U[idx]].size();++i){
			int v=adj[U[idx]][i];
			succ&=can(v,col[v]);
		}
		if(succ){
			printf("YES\n%d\n",U[idx]+1);
		}
		else{
			memset(vis,0,sizeof vis);
			vis[V[idx]]=1;
			succ=1;
			for(int i=0;i<adj[V[idx]].size();++i){
				int v=adj[V[idx]][i];
				succ&=can(v,col[v]);
			}
			if(succ){
				printf("YES\n%d\n",V[idx]+1);
			}
			else{
				printf("NO\n");
			}
		}
	}
	
	return 0;
}