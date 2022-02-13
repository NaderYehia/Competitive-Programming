#include<bits/stdc++.h>
using namespace std;
string a;
int nb,ns,nc,pb,ps,pc,b,s,c;
long long r;
bool canWeBake(long long x){
	long long tmp=0,fb,fs,fc;
	if(b>0 && nb/b<x){
		fb=nb/b;
		tmp+=(x*b-nb)*pb;
	}
	if(s>0 && ns/s<x ){
		fs=ns/s;
		tmp+=(x*s-ns)*ps;
	}
	if(c>0 && nc/c<x){
		fc=nc/c;
		tmp+=(x*c-nc)*pc;
	}
	if(tmp>r)
		return 0;
		return 1;
}
long long binarySearch(){
	long long lo=0,hi=1e13,mid;
	while(hi-lo>0){
		mid=(lo+hi+1)/2;
		if(canWeBake(mid))	lo=mid;
		else 	hi=mid-1;
		}
	return lo;
}
int main(){
	cin>>a;
	scanf("%d%d%d%d%d%d%lld",&nb,&ns,&nc,&pb,&ps,&pc,&r);
	int len=a.length();
	for(int i=0;i<len;++i)
		if(a[i]=='B')
			++b;
		else if(a[i]=='S')
			++s;
		else
			++c;
	printf("%lld",binarySearch());
}