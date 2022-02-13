#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	string s;
	bool b=0;
	cin>>s;
	int arr[26]={};
	for(int i=0;i<n;++i){
		if(s[i]<97)
			s[i]+=32;
		arr[s[i]-'a']++;
	}
	for(int i=0;i<26;++i)
		if(arr[i]==0){
			printf("NO");
			b=1;
			break;
		}
	if(!b)
		printf("YES");
}