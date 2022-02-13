#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 
const int N=2e5+7;
ll oo=0x3f3f3f3f;
int arr[N];
int R[N];
int t,n,m,k,r,a,b;
ll num,beb,cnt,cnt1;
string s,st;
bool f,fl;
double d;
int i;
int cm=1,sv=-1;
int freq[15];
ll mxs,nw;
vector<int>v;
deque<int>dq;
int frq[N];
int main(){
//	freopen("factors.in","r",stdin);
 
		int ans=oo;
		n=D();
		cin>>s;
		for(int i=0;i<n;++i)
			cin>>arr[i];
		for(int i=0;i<n;++i)
			if(s[i]=='R'&&s[i+1]=='L')
				ans=min(ans,(arr[i+1]-arr[i])/2);
		if(ans==oo)
			cout<<-1;
		else 
			cout<<ans;
	
 
		
 
	
	
	
	
	
	
}