#include<bits/stdc++.h>
using namespace std;
int n,a,arr[100005],mx;
int main(){
	cin>>n;
	for(int i=5;i<n+5;++i){
		cin>>a;
		arr[a+1]=0;
		arr[a-2]=0;
		arr[a]++;
		arr[a-1]++;
		mx=max(max(arr[a],arr[a-1]),mx);
	}
	cout<<mx;
}

