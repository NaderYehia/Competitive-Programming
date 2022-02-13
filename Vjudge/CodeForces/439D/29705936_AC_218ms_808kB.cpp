#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e9+7,OO=0x3f3f3f3f;

ll f(int x,vector<int> &a,vector<int> &b){
    ll cnt=0;
    for(int i=0;i<a.size();++i){
        if(a[i]<x)
            cnt+=abs(x-a[i]);
    }
    for(int i=0;i<b.size();++i){
        if(b[i]>x)
            cnt+=abs(b[i]-x);
    }
    return cnt;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<m;++i)
        scanf("%d",&b[i]);

    int lo=1,hi=1e9;
    while(hi-lo>3){
        int md0=lo+(hi-lo)/3,md1=lo+2*(hi-lo)/3;
        if(f(md0,a,b)>f(md1,a,b)) lo=md0;
        else hi=md1;
    }
    for(int i=lo;i<=hi;++i){
        if(f(i,a,b)<f(lo,a,b)) lo=i;
    }

    printf("%lld\n",f(lo,a,b));

    return 0;
}
