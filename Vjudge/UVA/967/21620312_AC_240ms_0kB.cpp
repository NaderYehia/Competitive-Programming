#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int i,j;
int arr[N];
int cm[N];

void sieve(){
	arr[0]=arr[1]=1;
	for(int i=2;i<=N/i;++i)
		if(arr[i]==0)
			for(int j=i*i;j<=N;j+=i)
				arr[j]=1;
}
int next(int x,int nd){
	int tmp=x%10;
	x/=10;
	for(int i=1;i<nd;++i)
		tmp*=10;
	return tmp+x;
}
bool ch(int x){
	if(arr[x]==1)
		return false;
	int s=0;
	int k=x;
	while(k){
		++s;
		k/=10;
	}
	for(int i=1;i<s;++i){
		x=next(x,s);
		if(arr[x]==1)
			return false;
	}
	return true;
}


int main(){
	sieve();
	for(int i=100;i<1000000;++i)
		if(ch(i))
			++cm[i];
			
	for(int i=100;i<=1000000;++i)
		cm[i]+=cm[i-1];

	while(cin>>i){
		if(i==-1)
			return 0;
		cin>>j;
		if(cm[j]-cm[i-1]==0)
			puts("No Circular Primes.");
		else if(cm[j]-cm[i-1]==1)
			puts("1 Circular Prime.");
		else
			printf("%d Circular Primes.\n",cm[j]-cm[i-1]);
	}
}