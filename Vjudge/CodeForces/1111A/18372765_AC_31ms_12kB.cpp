#include<iostream>
#include<string.h>
using namespace std;
bool vowl(char x){
	if(x=='a' || x=='e' || x=='o' ||x=='u' || x=='i')
	return true;
	else
	return false;
}
int main(){
	int i;
	char s[1001];
	char t[1001];
	cin>>s;
	cin>>t;
	if(strlen(s)==strlen(t)){
	int k=strlen(s);
	for( i=0;i<k;i++)
	if(!(vowl(s[i]) && vowl(t[i])) && !(!vowl(s[i]) && !vowl(t[i])) )
	break;
	if(i==k)
	cout<<"Yes";
	else 
	cout<<"No";
}
else
cout<<"No";
}
	