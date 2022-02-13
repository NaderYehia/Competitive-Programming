#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	bool ana=0;
	int len=a.length();
	for(int i=len-1;i>-1;--i){
		if(a[i]<'z'){
			++a[i];
			if(a<b){
				cout<<a<<"\n";
				ana=1;
				break;
			}
			else
				a[i]='a';
		}
		else 
		a[i]='a';
	}
	if(!ana)
		printf("No such string\n");
}