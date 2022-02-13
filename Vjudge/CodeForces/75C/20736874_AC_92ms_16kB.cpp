#include<bits/stdc++.h>
using namespace std;
int a,b,n,l,r;
bool p;
vector<int>v;
void getDivisors(int x){
	for(int i=1;i<=x/i;++i){
		if(x%i==0){
			v.push_back(i);
		if(i!=x/i)
			v.push_back(x/i);
		}
	}
}

int main(){
	scanf("%d%d",&a,&b);
	getDivisors(__gcd(a,b));
	sort(v.begin(),v.end());
	scanf("%d",&n);
	while(n--){
		p=0;
		scanf("%d%d",&l,&r);
		for(int i=v.size()-1;i>-1;--i)
			if(v[i]<=r&&v[i]>=l){
			printf("%d\n",v[i]);
			p=1;
			break;
		}
		if(!p)
			printf("-1\n");
	}
}