#include<bits/stdc++.h>

using namespace std;

const int N=150,SQ=320;

struct DSU{
	int par[N],sz[N],sets;
	void init(int n){
		fill(sz,sz+N,1);
		iota(par,par+N,0);
		sets=n;
	}
	int get_par(int u){
		return par[u]==u?u:par[u]=get_par(par[u]);
	}
	int merge(int u,int v){
		u=get_par(u);
		v=get_par(v);
		if(u==v) return 1;
		if(sz[v]>sz[u]) swap(u,v);
		par[v]=u;
		sz[u]+=sz[v];
		--sets;
		return 2;
	}
	bool oneCmp(){
		return sets==1;
	}
}dsu;

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	dsu.init(n);
	long long ans=1;
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		ans*=dsu.merge(u,v);
	}
	printf("%lld\n",ans);
}