#include<bits/stdc++.h>
using namespace std;
char arr[101]={0};
int main(){
	bool bad2t=false;
	int ones=0,twos=0,ths=0;
	scanf("%s",&arr);
	for(int i=0;i<100;i+=2){
		if(arr[i]=='1')
			++ones;
		else if(arr[i]=='2')
			++twos;
		else if(arr[i]=='3')
			++ths;
	}
	if(ones!=0){
		bad2t=true;
		--ones;
		printf("1");
		for(int i=0;i<ones;++i)
			printf("+1");
	}
	if(twos!=0){
		if(!bad2t){
		bad2t=true;
		--twos;
		printf("2");
	}
		for(int i=0;i<twos;++i)
			printf("+2");
	}
	if(ths!=0){
		if(!bad2t){
		bad2t=true;
		--ths;
		printf("3");
	}
		for(int i=0;i<ths;++i)
			printf("+3");
	}
	printf("\n");
	
}