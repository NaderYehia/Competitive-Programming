#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;

ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t --> 0){

        ll x1,x2,y1,y2;
        char ch;
        scanf("%lld %lld %c %lld %lld",&x1,&x2,&ch,&y1,&y2);

        if(ch=='*'){
            ll g=__gcd(x1*y1,x2*y2);
            ll l=(x1*y1)/g;
            ll r=(x2*y2)/g;
            if(l>0&&r<0) l*=-1,r*=-1;
            printf("%lld / %lld\n",l,r);
        }
        else if(ch=='/'){
            ll g=__gcd(x1*y2,x2*y1);
            ll l=(x1*y2)/g;
            ll r=(x2*y1)/g;
            if(l>0&&r<0) l*=-1,r*=-1;
            printf("%lld / %lld\n",l,r);
        }
        else if(ch=='+'){
            ll l=lcm(x2,y2);
            ll r=(l/x2*x1+l/y2*y1);
            ll g=__gcd(l,r);
            l/=g;
            r/=g;
            if(r>0&&l<0) l*=-1,r*=-1;
            printf("%lld / %lld\n",r,l);
        }
        else{
            ll l=lcm(x2,y2);
            ll r=(l/x2*x1-l/y2*y1);
            ll g=__gcd(l,r);
            l/=g;
            r/=g;
            if(r>0&&l<0) l*=-1,r*=-1;
            printf("%lld / %lld\n",r,l);
        }

    }
    return 0;
}
