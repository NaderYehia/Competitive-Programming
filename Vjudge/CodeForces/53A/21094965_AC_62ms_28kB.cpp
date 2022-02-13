#include<bits/stdc++.h>
using namespace std;
string s;
string arr;
vector<string>v;
int n;
bool a=0;
int main(){
	cin>>s;
	cin>>n;
	int len=s.length();
	for(int i=0;i<n;++i){
		a=0;
		cin>>arr;
		for(int j=0;j<len;++j)
			if(s[j]!=arr[j])
				a=1;
		if(!a)
			v.push_back(arr);
	}
	sort(v.begin(),v.end());
	v.size()>0?cout<<v[0]:cout<<s;
	
}