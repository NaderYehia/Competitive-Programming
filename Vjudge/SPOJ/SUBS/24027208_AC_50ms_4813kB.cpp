#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int t,n,k;
string x,y;

bool can(int M){
    if(x.length()*1ll*M>y.length())
        return 0;
    string s;
    for(int i=0;x[i];++i)
        for(int j=0;j<M;++j)
            s+=x[i];
    int i=0;
    for(int j=0;y[j];++j){
        if(s[i]==y[j])
            ++i;
    }
    if(i==s.length())
        return 1;
    return 0;
}

long long bs(){
    long long lo=0,hi=1e6,mid;
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
    scanf("%d",&t);
    while(t--){
        cin>>x>>y;
        printf("%d\n",bs());
    }
    return 0;
}
