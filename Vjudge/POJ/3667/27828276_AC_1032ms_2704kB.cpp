#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N=5e4+5,OO=0x3f3f3f3f;
int t,n,m;

struct node{
    int pre,suf,best,lz;

    void addLazy(int ss,int se,int v){
        pre=suf=best=(se-ss+1)*v;
        lz=v;
    }
};

node seg[4*N];

void merge(int si,int ss,int se){
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    node &c=seg[si],&l=seg[lf],&r=seg[rt];
    c.pre=(l.pre==md-ss+1)?l.pre+r.pre:l.pre;
    c.suf=(r.suf==se-md)?r.suf+l.suf:r.suf;
    c.best=max(max(l.best,r.best),l.suf+r.pre);
}

void build(int si=0,int ss=0,int se=n-1){
    node &c=seg[si];
    c.lz=-1;
    if(ss==se){
        c.pre=c.suf=c.best=1;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    merge(si,ss,se);
}

void pushDown(int si,int ss,int se){
    if(ss==se||seg[si].lz==-1) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    node &c=seg[si],&l=seg[lf],&r=seg[rt];
    l.addLazy(ss,md,c.lz);
    r.addLazy(md+1,se,c.lz);
    c.lz=-1;
}

void setRange(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(ss,se,qv);
        return;
    }
    pushDown(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    setRange(qs,qe,qv,lf,ss,md);
    setRange(qs,qe,qv,rt,md+1,se);
    merge(si,ss,se);
}

int query(int sz,int si=0,int ss=0,int se=n-1){
    node &c=seg[si];
    if(sz>c.best) return -1;
    if(c.pre>=sz) return ss;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    node &l=seg[lf],&r=seg[rt];
    if(l.best>=sz) return query(sz,lf,ss,md);
    if(l.suf+r.pre>=sz) return md-l.suf+1;
    return query(sz,rt,md+1,se);
}

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    build();
    while(m--){
        int op,id,sz;scanf("%d",&op);
        if(op==1){
            scanf("%d",&sz);
            id=query(sz);
            if(~id) setRange(id,id+sz-1,0);
            printf("%d\n",id+1);
        }
        else{
            scanf("%d%d",&id,&sz);
            --id;
            setRange(id,id+sz-1,1);
        }

    }
    return 0;
}
