#include<iostream>
using namespace std;
int main(){
	int t,n,s,j=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=0;
		for(int i=0;i<n;++i){
			int a ; scanf("%d",&a);
			s+=a;
		}
		printf("Case %d: %d\n",j,s);
		j++;
	}
}