#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	pair<int,int>p[n];
	for(int i=0;i<n;++i){
		scanf("%d%d",&p[i].first,&p[i].second);
		p[i].second*=-1;
	}
	sort(p,p+n);
	for(int i=0;i<n;++i){
		printf("%d %d\n",p[i].first,-p[i].second);
	}
}
}