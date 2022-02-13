#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,m,k;
string s;
ll nb,ns,nc,pb,ps,pc,r,B,S,C;

bool can(ll x){
    ll tmp=0;
    if(x*B>nb){
        tmp+=(x*B-nb)*pb;
    }
    if(x*S>ns){
        tmp+=(x*S-ns)*ps;
    }
    if(x*C>nc){
        tmp+=(x*C-nc)*pc;
    }
    return tmp<=r;
}
//333333333334
ll bs(){
    ll lo=0,hi=1e13,mid;
    while(lo<hi){
        mid=lo+(hi-lo+1)/2;
        if(can(mid)) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    cin>>s;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    for(int i=0;s[i];++i)
        if(s[i]=='B')
            ++B;
        else if(s[i]=='S')
            ++S;
        else if(s[i]=='C')
            ++C;
    cout<<bs();
    return 0;
}
