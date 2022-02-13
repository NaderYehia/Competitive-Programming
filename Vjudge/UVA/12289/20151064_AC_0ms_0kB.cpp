#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	char a[6]={0};
	while(n--){
		bool o=0,n=0,e=0,t=0,w=0;
		scanf("%s",&a);
		if(strlen(a)>3){
			printf("3\n");
			continue;
		}
		if((a[0]=='o' && a[1]=='n')|| (a[0]=='o' &&a[2]=='e' ) || (a[2]=='e'&& a[1]=='n'))
			printf("1\n");
		else 
			printf("2\n");
	}	

}