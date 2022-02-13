#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	bool f=1;
	scanf("%d",&n);
	if(n>0)
		printf("I hate");
	for(int i=1;i<n;++i){
		if(f)
			printf(" that I love");
		else
			printf(" that I hate");
			f=!f;
	}
	printf(" it");
}