#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a=0,c=0,g=0,t=0;
	char arr[256]={0};
	scanf("%d",&n);
	if(n%4!=0)
		printf("===");
	else{
		scanf("%s",&arr);
		for(int i=0;i<n;++i){
			if(arr[i]=='A')
				++a;
			else if(arr[i]=='C')
				++c;
			else if(arr[i]=='G')
				++g;
			else if(arr[i]=='T')
				++t;
		}
		if(a>n/4 || c>n/4 || g>n/4 || t>n/4)
			printf("===");
		else {
			for(int i=0;i<n;++i){
				if(arr[i]=='?'){
					if(n/4>a){
						printf("A");
						++a;
						continue;
					}
					 if(n/4>c){
						printf("C");
						++c;
						continue;
					}
					 if(n/4>g){
						printf("G");
						++g;
						continue;
					}
					 if(n/4>t){
						printf("T");
						++t;
						continue;
				}
				}
				else 
					printf("%c",arr[i]);
			}
			printf("\n");
		}
	}
}