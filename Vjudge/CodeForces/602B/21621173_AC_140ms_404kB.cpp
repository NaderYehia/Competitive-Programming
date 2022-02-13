#include<bits/stdc++.h>
using namespace std;
int n,a,arr[100005],mx;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		a-1>-1?arr[a-1]=0:0;
		arr[a+2]=0;
		arr[a]++;
		arr[a+1]++;
		mx=max(max(arr[a],arr[a+1]),mx);
	}
	cout<<mx;
}

