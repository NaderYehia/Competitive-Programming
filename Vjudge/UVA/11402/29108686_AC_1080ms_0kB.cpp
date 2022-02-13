#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1<<20,M=1e9+7,OO=0x3f3f3f3f;

int n;
char s[N];

struct node{
    int sum,lz,inv;

    void mutate(int v,int ss,int se){
        sum=(se-ss+1)*v;
        lz=v;
        inv=0;
    }

    void inverse(int ss,int se){
        sum=(se-ss+1)-sum;
        inv+=1;
    }
};

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    seg[si].lz=-1,seg[si].inv=0;
    if(ss==se){
        seg[si].sum=s[ss]-'0';
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

void push_Down(int si,int ss,int se){
    if(ss==se||(seg[si].lz==-1&&seg[si].inv%2==0)) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    if(~seg[si].lz){
        seg[lf].mutate(seg[si].lz,ss,md);
        seg[rt].mutate(seg[si].lz,md+1,se);
        seg[si].lz=-1;
    }
    if(seg[si].inv%2){
        seg[lf].inverse(ss,md);
        seg[rt].inverse(md+1,se);
        seg[si].inv=0;
    }
}

void update(int qs,int qe,int op,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        if(op){
            seg[si].inverse(ss,se);
        }
        else{
            seg[si].mutate(qv,ss,se);
        }
        return;
    }
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qs,qe,op,qv,lf,ss,md);
    update(qs,qe,op,qv,rt,md+1,se);
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

    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("Case %d:\n",tc);
        n=0;
        int m;
        scanf("%d",&m);
        while(m--){
            int len;char temp[N];
            scanf("%d%s",&len,temp);
            while(len--){
                for(int i=0;temp[i];++i)
                    s[n++]=temp[i];
            }
        }
        build();
        int q,qc=1;
        scanf("%d",&q);
        while(q--){
            char op;int l,r;
            scanf(" %c%d%d",&op,&l,&r);
            if(op=='F'){
                update(l,r,0,1);
            }
            if(op=='E'){
                update(l,r,0,0);
            }
            if(op=='I'){
                update(l,r,1,0);
            }
            if(op=='S'){
                printf("Q%d: %d\n",qc++,query(l,r));
            }
        }
    }

    return 0;
}
