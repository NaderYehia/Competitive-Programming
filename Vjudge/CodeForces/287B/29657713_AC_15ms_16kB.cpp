#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;


ll quan(ll x,ll y){
    return (x*(x+1)/2)-(y*(y+1)/2)+1;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k*(k-1)/2+1<n){
        printf("-1\n");
    }
    else{
        int lo=0,hi=k-1;
        while(lo<hi){
            int md=lo+(hi-lo)/2;
            if(quan(k-1,k-md-1)>=n) hi=md;
            else lo=md+1;
        }
        printf("%d\n",lo);
    }

    return 0;
}
