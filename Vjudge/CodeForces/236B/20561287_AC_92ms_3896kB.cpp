#include<iostream>

using namespace std;

int a,b,c;


int main(){
	scanf("%d%d%d",&a,&b,&c);
	int n=a*b*c;
	int arr[n+5]={};
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i)
			++arr[j];
	}
	long long sum=0;
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;++j){
			for(int k=1;k<=c;++k){
				sum+=arr[i*j*k];
			}
		}
	}
	printf("%d",sum%1073741824);
}