#include<bits/stdc++.h>
using namespace std;
string a;
int n;
long long sum;
int main(){
	scanf("%d",&n);
	while(n--){
		sum=0;
		cin>>a;
		for(int i=0;i<a.length();++i)
			sum+=a[i]-'0';
		printf("%d\n",sum);
                a.clear();
	}
}