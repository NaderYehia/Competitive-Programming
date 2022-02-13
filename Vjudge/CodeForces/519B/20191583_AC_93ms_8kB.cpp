#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	long long c=0,c1=0,c2=0;
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		c+=a;
	}
	for(int i=0;i<n-1;++i){
		scanf("%d",&a);
		c1+=a;
	}
	for(int i=0;i<n-2;++i){
		scanf("%d",&a);
		c2+=a;
	}
	cout<<c-c1<<"\n"<<c1-c2;
			
}