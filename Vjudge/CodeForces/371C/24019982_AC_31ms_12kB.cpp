#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int t,n,k;
int nb,ns,nc,pb,ps,pc,B,S,C;
long long r;

bool can(long long ham){
    long long tmp=r;
    if(ham*1ll*B>nb){
        if(tmp<(ham*1ll*B-nb)*1ll*pb)
            return 0;
        else
            tmp-=(ham*1ll*B-nb)*1ll*pb;
    }
    if(ham*1ll*S>ns){
        if(tmp<(ham*1ll*S-ns)*1ll*ps)
            return 0;
        else
            tmp-=(ham*1ll*S-ns)*1ll*ps;
    }
    if(ham*1ll*C>nc){
        if(tmp<(ham*1ll*C-nc)*1ll*pc)
            return 0;
        else
            tmp-=(ham*1ll*C-nc)*1ll*pc;
    }
    return 1;
}

long long bs(){
    long long lo=0,hi=1e13,mid;
    while(hi-lo>0){
        mid=(lo+hi+1)/2;
        if(can(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int main(){
    string s;
    cin>>s;
    for(int i=0;s[i];++i)
        if(s[i]=='B')
            ++B;
        else if(s[i]=='S')
            ++S;
        else
            ++C;
    scanf("%d%d%d%d%d%d%lld",&nb,&ns,&nc,&pb,&ps,&pc,&r);
    printf("%lld",bs());
    return 0;
}
