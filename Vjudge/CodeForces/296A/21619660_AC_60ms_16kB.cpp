#include<bits/stdc++.h>
using namespace std;
int arr[120],frq[1500];
int main(){
	int n,mx=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		frq[arr[i]]++;
	}
	for(int i=0;i<1004;++i)
		mx=max(mx,frq[i]);
	if(n&1){
		if(n/2+1>=mx)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	else {
		if(n/2>=mx)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}