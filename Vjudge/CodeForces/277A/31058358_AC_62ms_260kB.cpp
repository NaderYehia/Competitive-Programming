#include<bits/stdc++.h>

using namespace std;

const int N=200;

struct DSU{
	int par[N],sz[N],sets;
	void init(int n){
		iota(par,par+N,0);
		fill(sz,sz+N,1);
		sets=n;
	}
	int get(int p){
		return par[p]==p?p:par[p]=get(par[p]);
	}
	void merge(int u,int v){
		u=get(u);
		v=get(v);
		if(u==v) return;
		if(sz[v]>sz[u]) swap(u,v);
		sz[u]+=sz[v];
		par[v]=u;
		--sets;
	}
}dsu;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<int>> v(m+1);
	bool haa=0;
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		haa|=(k!=0);
		for(int j=0;j<k;++j){
			int lan;
			scanf("%d",&lan);
			v[lan].push_back(i);
		}
	}
	dsu.init(n);
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=j+1;k<v[i].size();++k){
				dsu.merge(v[i][j],v[i][k]);
			}
		}
	}
	printf("%d\n",dsu.sets-haa);
	
	return 0;
}