#include<iostream>
using namespace std;
int n,k,w;
long long s;
int main(){
	scanf("%d%d%d",&k,&n,&w);
	for(int i=1;i<w+1;++i){
		s+=i*k;
	}
	printf("%d",s-n>0?s-n:0);
}