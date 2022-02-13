#include<bits/stdc++.h>
using namespace std;
map<string,int>mp1;
map<string,int>mp2;
string nn[120],mm[120];
int main(){
	int n,m,mx=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>nn[i];
		mp1[nn[i]]++;
	}
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>mm[i];
		mp2[mm[i]]++;
	}
	for(int i=0;i<n;++i){
		mx=max(mx,mp1[nn[i]]-mp2[nn[i]]);
	}
	cout<<mx<<endl;

}