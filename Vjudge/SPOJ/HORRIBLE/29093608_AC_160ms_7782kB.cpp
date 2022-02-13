#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

struct node{
    ll sum, lz;

    void addLazy(ll v,int ss,int se){
        sum+=v*(se-ss+1);
        lz+=v;
    }
};

node seg[4*N];
int n;
void build(int si=0,int ss=0,int se=n-1){
    seg[si].sum=seg[si].lz=0;
    if(ss==se){
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
}

void push_Down(int si,int ss,int se){
    if(ss==se||seg[si].lz==0) return;
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    seg[lf].addLazy(seg[si].lz,ss,md);
    seg[rt].addLazy(seg[si].lz,md+1,se);
    seg[si].lz=0;
}

void update(int qs,int qe,ll qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(qv,ss,se);
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    push_Down(si,ss,se);
    update(qs,qe,qv,lf,ss,md);
    update(qs,qe,qv,rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

ll query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si].sum;
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d%d",&n,&q);
        build();
        while(q--){
            int op,l,r,v;
            scanf("%d%d%d",&op,&l,&r);
            --l,--r;
            if(op==0){
                scanf("%d",&v);
                update(l,r,v);
            }
            else{
                printf("%lld\n",query(l,r));
            }
        }
    }

    return 0;
}
