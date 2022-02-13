#include<iostream>
using namespace std;
bool arr[3005];
void sieve (int k){
	for(int i=2;i<=k/i;++i){
		if(!arr[i]){
			for(int j=i*i;j<=k;j+=i){
				arr[j]=1;
			}
		}
		}
}
int main(){
	int n,s=0,cnt;
	scanf("%d",&n);
	sieve(n);
	for(int i=6;i<=n;++i){
		cnt=0;
		for(int j=2;j<=n;++j)
			if(!arr[j])
				if(i>j && i%j==0)
						++cnt;
		if(cnt==2)
			++s;
		}
		
	
	printf("%d",s);
}