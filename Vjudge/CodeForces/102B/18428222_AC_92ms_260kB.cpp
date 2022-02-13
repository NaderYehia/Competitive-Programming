#include<iostream>
#include<string.h>
using namespace std;
int c=0;
int sum(int x){
	int kek=0;
while(x>0){
	kek+=x%10;
	x/=10;
}
return kek;
}
int main(){
	string s;
	cin>>s;
	int fsum=0;
	if(s.length()<2){
	cout<<c;
	return 0;
	}
	for(int i=0;i<s.length();++i)
		fsum+=s[i]-'0';
		++c;
	while(fsum>9){
		fsum=sum(fsum);
		++c;
	}
	cout<<c;
}