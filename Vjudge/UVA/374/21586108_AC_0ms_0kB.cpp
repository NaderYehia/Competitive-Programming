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

const int N=1e3+7;
ll oo=0x3f3f3f3f3f3f3f3f;
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
ll power(ll a, ll b, ll m){
    if(!b)  return 1;
    ll t = power(a, b>>1, m)%m;
    return ((t*t)%m * (b&1 ? a : 1)%m)%m;
}
int main(){
//	freopen("factors.in","r",stdin);

		while(cin>>n>>m>>k){
			cout<<power(n,m,k)<<endl;
		}

		

	

	
	
	
	
}