#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;

struct node{
    ll sum,lazy;

    void addLazy(ll val,int ss,int se){
        sum+=val*(se-ss+1);
        lazy+=val;
    }
};

node seg[SEGM];

void pushDown(int si,int ss,int se){
    node &cur=seg[si];
    if(cur.lazy==0||ss==se) return;
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    seg[lf].addLazy(cur.lazy,ss,md);
    seg[rt].addLazy(cur.lazy,md+1,se);
    cur.lazy=0;
}


void updateRange(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(qv,ss,se);
        return;
    }
    pushDown(si,ss,se);
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    updateRange(qs,qe,qv,lf,ss,md);
    updateRange(qs,qe,qv,rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si].sum=seg[si].lazy=0;
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
    seg[si].lazy=0;
}

ll query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si].sum;
    pushDown(si,ss,se);
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int t,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        build();
        while(q--){
            int op,a,b,val;
            scanf("%d",&op);
            if(op){
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(--a,--b));
            }else{
                scanf("%d%d%d",&a,&b,&val);
                updateRange(--a,--b,val);
            }
        }
    }
    return 0;
}
