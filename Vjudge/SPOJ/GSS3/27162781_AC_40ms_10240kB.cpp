#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e4+5,M=1<<30,SEGM=4*N,OO=0x3f3f3f3f;
int n;
int arr[N];
 
struct node{
    ll pre,suf,best,sum;
 
    node(){
        pre=suf=best=-1e9;
        sum=0;
    }
 
    node(int v){
        pre=suf=best=sum=v;
    }
};
 
node seg[SEGM];
 
node operator+(const node &lf,const node &rt){
    node ret;
    ret.pre=max(lf.pre,lf.sum+rt.pre);
    ret.suf=max(rt.suf,rt.sum+lf.suf);
    ret.best=max(max(lf.best,rt.best),lf.suf+rt.pre);
    ret.sum=lf.sum+rt.sum;
    return ret;
}
 
void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si]=node(arr[ss]);
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}
 
void update(int qi,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qi||se<qi) return;
    if(ss==se){
        seg[si]=node(arr[ss]=qv);
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    update(qi,qv,lf,ss,md);
    update(qi,qv,rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}
 
node query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return node();
    if(ss>=qs&&se<=qe){
        return seg[si];
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}
 
int main(){
    //freopen("myfile.txt","w",stdout);
    int q;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    build();
    scanf("%d",&q);
    while(q--){
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(op) printf("%lld\n",query(--a,--b).best);
        else update(--a,b);
    }
    return 0;
}