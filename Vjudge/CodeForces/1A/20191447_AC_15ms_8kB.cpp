#include<iostream>
using namespace std;
int main(){
	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);
	long long l=n/a;
	long long r=m/a;
	if(n%a!=0)
		++l;
	if(m%a!=0)
		++r;
	cout<<l*r;
}