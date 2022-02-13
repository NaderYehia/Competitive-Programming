#include<iostream>
#include<string.h>
using namespace std;
int main(){
	long long petya=0,vasya=0;
	int n;
	int in[100001];
	cin>>n;
	for(int i=0;i<n;i++){
	int k;
	cin>>k;
	in[k]=i;
	}
	int m;
	cin>>m;
	while(m--){
		int a;
		cin>>a;
		petya+=in[a]+1;
		vasya+=n-in[a];
	}
	cout<<petya<<" "<<vasya;
}
	