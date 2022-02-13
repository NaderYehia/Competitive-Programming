#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char a[4];
	char b[4];
	char c[4];
	int s[]={0,0,0};
	char o[4];
	cin>>a;
	cin>>b;
	cin>>c;
	if(a[1]=='>'){
		a[1]='<';
		char temp=a[0];
		a[0]=a[2];
		a[2]=a[0];
	}
	if(c[1]=='>'){
		c[1]='<';
		char temp=c[0];
		c[0]=c[2];
		c[2]=c[0];
	}
	if(b[1]=='>'){
		b[1]='<';
		char temp=b[0];
		b[0]=b[2];
		b[2]=b[0];
	}
	if(a[0]=='A')
	s[0]=s[0]+1;
	else if(a[0]=='B')
	s[1]=s[1]+1;
	else
	s[2]=s[2]+1;
	if(b[0]=='A')
	s[0]=s[0]+1;
	else if(b[0]=='B')
	s[1]=s[1]+1;
	else 
	s[2]=s[2]+1;
	if(c[0]=='A')
	s[0]=s[0]+1;
	else if(c[0]=='B')
	s[1]=s[1]+1;
	else
	s[2]=s[2]+1;
	bool k2=false;
	bool k1=false;
	bool k0=false;
for(int i=0;i<3;i++){
	if(s[i]==2){
	o[0]=(char)(i+65);
	k2=true;
	}
	else if(s[i]==1){
	o[1]=(char)(i+65);
	k1=true;
	}
	else if(s[i]==0){
	k0=true;
	o[2]=(char)(i+65);
	}
}
o[3]='\0';
if(k0==false || k1==false || k2==false)
cout<<"Impossible";
else 
cout<<o;
}