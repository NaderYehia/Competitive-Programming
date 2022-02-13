#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+5,M=1e9+7,OO=0x3f3f3f3f;

bool prime[N];
void sieve(){
    fill(prime,prime+N,1);
    prime[0]=prime[1]=0;
    for(int i=2;i<=N/i;++i){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i)
                prime[j]=0;
        }
    }
}


int n,m;
int arr[N];

struct node{
    int sum,lz;

    void addLazy(int v,int ss,int se){
        sum=v*(se-ss+1);
        lz=v;
    }
};

node seg[N];

void build(int si=0,int ss=0,int se=n-1){
    seg[si].lz=-1;
    if(ss==se){
        seg[si].sum=prime[arr[ss]];
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].sum=seg[lf].sum+seg[rt].sum;
}

void push_Down(int si,int ss,int se){
    if(ss==se||seg[si].lz==-1) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    seg[lf].addLazy(seg[si].lz,ss,md);
    seg[rt].addLazy(seg[si].lz,md+1,se);
    seg[si].lz=-1;
}

void update(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(prime[qv],ss,se);
        return;
    }
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qs,qe,qv,lf,ss,md);
    update(qs,qe,qv,rt,md+1,se);
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

    sieve();

    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("Case %d:\n",tc);
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);

        build();

        while(m--){
            int op,l,r,v;
            scanf("%d%d%d",&op,&l,&r);
            --l,--r;
            if(op==0){
                scanf("%d",&v);
                update(l,r,v);
            }
            else{
                printf("%d\n",query(l,r));
            }
        }

    }

    return 0;
}
