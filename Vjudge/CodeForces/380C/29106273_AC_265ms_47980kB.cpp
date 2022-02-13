#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
char s[N];

struct node{
    int open,close,sum;
};

node operator+(const node &lf,const node &rt){
    node ret;
    int to_merge=min(lf.open,rt.close);
    ret.open=lf.open+rt.open-to_merge;
    ret.close=lf.close+rt.close-to_merge;
    ret.sum=lf.sum+rt.sum+2*to_merge;
    return ret;
}

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si].open=(s[ss]=='(');
        seg[si].close=(s[ss]==')');
        seg[si].sum=0;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

node identity;
node query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return identity;
    if(ss>=qs&&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    identity.close=identity.open=identity.sum=0;

    scanf("%s",s);
    n=strlen(s);

    build();

    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        --l,--r;
        printf("%d\n",query(l,r).sum);
    }

    return 0;
}
