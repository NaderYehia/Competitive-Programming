#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5,M=1e9+7,OO=0x3f3f3f3f;

int n;
int arr[N];

struct node{
    vector<int> v;
    int g;
};

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    seg[si].v.clear();
    if(ss==se){
        seg[si].g=arr[ss];
        seg[si].v.push_back(arr[ss]);
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].g=__gcd(seg[lf].g,seg[rt].g);
    merge(seg[lf].v.begin(),seg[lf].v.end(),seg[rt].v.begin(),seg[rt].v.end(),inserter(seg[si].v,seg[si].v.begin()));
}

int mn(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return OO;
    if(ss>=qs&&se<=qe) return seg[si].v[0];
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return min(mn(qs,qe,lf,ss,md),mn(qs,qe,rt,md+1,se));
}

int cnt(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return int(upper_bound(seg[si].v.begin(),seg[si].v.end(),qv)-lower_bound(seg[si].v.begin(),seg[si].v.end(),qv));
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return cnt(qs,qe,qv,lf,ss,md)+cnt(qs,qe,qv,rt,md+1,se);
}

int gc(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si].g;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return __gcd(gc(qs,qe,lf,ss,md),gc(qs,qe,rt,md+1,se));
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();

    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        --l,--r;
        int MN=mn(l,r);
        int CNT=cnt(l,r,MN);
        int GC=gc(l,r);
        if(MN==GC){
            printf("%d\n",r-l+1-CNT);
        }
        else{
            printf("%d\n",r-l+1);
        }
    }


    return 0;
}
