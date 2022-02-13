#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int N=1e6;
	char s[N];
	int a,m;
	cin>>s;
	cin>>m;
	int len=strlen(s);
	int cm[len]={0};
	while(m--){
		cin>>a;
		cm[a]+=1;
		cm[len-a+1]-=1;
	}
	for(int i=1;i<=len/2;i++){
		cm[i]+=cm[i-1];
		if(cm[i]%2!=0)
		swap(s[i-1],s[len-i]);
}
cout<<s;
}