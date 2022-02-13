#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum[++n]={0};
	for(int i=1;i<n;++i){
		int x;
		cin>>x;
		sum[i]=sum[i-1]+x;
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<sum[y+1]-sum[x]<<"\n";
	}
}