#include<bits/stdc++.h>

using namespace std;

const int N=300+10,SQ=320;

char grid[N][N];

bool vis[N];
int n;
vector<int> v;

void dfs(int u){
	vis[u]=1;
	v.push_back(u);
	for(int i=0;i<n;++i){
		if(grid[u][i]=='1'&&!vis[i])
			dfs(i);
	}
}

int main(){
	
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;++i)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<n;++i)
		scanf("%s",grid[i]);
	
	vector<int> ans(n);
	for(int i=0;i<n;++i){
		if(!vis[i]){
			dfs(i);
			vector<int> temp;
			for(int i=0;i<v.size();++i)
				temp.push_back(arr[v[i]]);
			sort(temp.begin(),temp.end());
			sort(v.begin(),v.end());
			for(int i=0;i<v.size();++i)
				ans[v[i]]=temp[i];
			v.clear();
		}
	}
	
	for(int i=0;i<n;++i) printf("%d ",ans[i]);
	
}