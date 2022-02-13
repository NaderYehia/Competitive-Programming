#include<iostream>
using namespace std;
int main(){
	int n,i=0;
	cin>>n;
	int r=n/2;
	int l=r-1;
	char a[n];
	char b[n];
	cin>>a;
	if(n&1){
		b[n/2]=a[0];
		i++;
		r=n/2+1;
		l=n/2-1;	
	}
	bool left=true;
	for(;i<n;i++){
		if(left)
			b[l--]=a[i];
		else
			b[r++]=a[i];
		left=!left;
	}
	b[n]='\0';
	cout<<b;
}