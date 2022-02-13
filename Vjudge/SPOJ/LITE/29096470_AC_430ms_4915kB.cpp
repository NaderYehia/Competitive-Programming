#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n,m;

struct node{
    int sum,lz;

    void addLazy(int ss,int se){
        sum=(se-ss+1)-sum;
        lz+=1;
    }
};

node seg[4*N];

void push_Down(int si,int ss,int se){
    if(ss==se||seg[si].lz%2==0) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    seg[lf].addLazy(ss,md);
    seg[rt].addLazy(md+1,se);
    seg[si].lz=0;
}

void update(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(ss,se);
        return;
    }
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qs,qe,lf,ss,md);
    update(qs,qe,rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

int query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si].sum;
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d",&n,&m);

    while(m--){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        --l,--r;
        if(op==0){
            update(l,r);
        }
        else{
            printf("%d\n",query(l,r));
        }
    }

    return 0;
}
