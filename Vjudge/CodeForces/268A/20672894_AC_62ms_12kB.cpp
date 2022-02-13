#include<iostream>
using namespace std;
int n,cnt=0,a[35],b[35];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i]==b[j])
				++cnt;
		}
	}
	printf("%d",cnt);
}