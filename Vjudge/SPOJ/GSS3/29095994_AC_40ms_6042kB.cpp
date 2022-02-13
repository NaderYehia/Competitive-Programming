#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
int arr[N];

struct node{
    int pre,suf,best,sum;
};

node seg[4*N];

node operator+(const node &lf,const node &rt){
    node ret;
    ret.pre=max(lf.pre,lf.sum+rt.pre);
    ret.suf=max(rt.suf,rt.sum+lf.suf);
    ret.best=max(lf.suf+rt.pre,max(lf.best,rt.best));
    ret.sum=lf.sum+rt.sum;
    return ret;
}

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si].best=seg[si].pre=seg[si].suf=seg[si].sum=arr[ss];
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

void update(int qi,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        seg[si].best=seg[si].pre=seg[si].suf=seg[si].sum=qv;
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qi,qv,lf,ss,md);
    update(qi,qv,rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    identity.pre=-OO;
    identity.suf=-OO;
    identity.best=-OO;
    identity.sum=0;

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();

    int q;
    scanf("%d",&q);
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==0){
            --x;
            update(x,y);
        }
        else{
            --x,--y;
            printf("%d\n",query(x,y).best);
        }
    }

    return 0;
}
