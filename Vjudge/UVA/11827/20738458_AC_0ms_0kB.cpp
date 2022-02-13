#include<bits/stdc++.h>
using namespace std;
int n,arr[105];
vector<int>v;
int main(){
	scanf("%d\n",&n);
	while(n--){
		v.clear();
		int n;
		string c;
		getline(cin,c);
		istringstream s(c);
		while(s>>n)
			v.push_back(n);
		int gc=0;
		for(int i=0;i<v.size();++i)
			for(int j=i+1;j<v.size();++j){
				gc=max(gc,__gcd(v[i],v[j]));
			}	
		printf("%d\n",gc);
	
	}
}