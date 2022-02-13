#include<iostream>
using namespace std;
int main(){
	int n,q,x,y;
	scanf("%d",&n);
	int arr[n+1]={};
	for(int i=1;i<n+1;++i){
		scanf("%d",&x);
		arr[i]=x+arr[i-1];
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",arr[y+1]-arr[x]);
	}
	}