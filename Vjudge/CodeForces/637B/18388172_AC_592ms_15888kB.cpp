#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int main(){
	map<string,bool>mp;
	int N;
	int q;
	cin>>N;
	string a[N];
	for(int i=0;i<N;i++)
	cin>>a[i];
	for(int k=N-1;k>=0;k--){
		if(!mp[a[k]]){
			cout<<a[k]<<"\n";
			mp[a[k]]=true;
		}
	}
	
}