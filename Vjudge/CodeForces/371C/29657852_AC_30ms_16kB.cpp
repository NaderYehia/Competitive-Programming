#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e3+7,OO=0x3f3f3f3f;

ll nb,ns,nc;
ll pb,ps,pc;
ll r;
int B=0,S=0,C=0;

bool can(ll x){
    ll cur=r;

    if(x*B>nb){
        ll rem=-nb+(x*B);
        cur-=rem*pb;
    }

    if(S*x>ns){
        ll rem=-ns+(x*S);
        cur-=rem*ps;
    }

    if(C*x>nc){
        ll rem=-nc+(x*C);
        cur-=rem*pc;
    }
    return cur>=0;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    char s[N];
    scanf("%s",s);

    scanf("%d%d%d",&nb,&ns,&nc);
    scanf("%d%d%d",&pb,&ps,&pc);
    scanf("%lld",&r);

    for(int i=0;s[i];++i)
        if(s[i]=='B') ++B;
        else if(s[i]=='C') ++C;
        else ++S;

    ll lo=0,hi=1e13;
    while(lo<hi){
        ll md=lo+(hi-lo+1)/2;
        if(can(md)) lo=md;
        else hi=md-1;
    }

    printf("%lld\n",lo);



    return 0;
}
