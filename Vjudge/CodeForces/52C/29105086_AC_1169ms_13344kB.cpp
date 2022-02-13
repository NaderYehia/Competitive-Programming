#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;

int n;
int arr[N];

struct node{
    ll mn,lz;

    void addLazy(int v){
        mn+=v;
        lz+=v;
    }
};

node seg[4*N];

void build(int si=0,int ss=0,int se=n-1){
    seg[si].lz=0;
    if(ss==se){
        seg[si].mn=arr[ss];
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si].mn=min(seg[lf].mn,seg[rt].mn);
}

void push_Down(int si,int ss,int se){
    if(ss==se||seg[si].lz==0) return;
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    seg[lf].addLazy(seg[si].lz);
    seg[rt].addLazy(seg[si].lz);
    seg[si].lz=0;
}

void update(int qs,int qe,int qv,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return;
    if(ss>=qs&&se<=qe){
        seg[si].addLazy(qv);
        return;
    }
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    update(qs,qe,qv,lf,ss,md);
    update(qs,qe,qv,rt,md+1,se);
    seg[si].mn=min(seg[lf].mn,seg[rt].mn);
}

ll query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return ll(1e18);
    if(ss>=qs&&se<=qe) return seg[si].mn;
    push_Down(si,ss,se);
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return min(query(qs,qe,lf,ss,md),query(qs,qe,rt,md+1,se));
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    build();

    int q;
    scanf("%d\n",&q);
    while(q--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int cnt=0,temp,l,r,v;
        while(ss>>temp){
            if(cnt==0) l=temp;
            if(cnt==1) r=temp;
            if(cnt==2) v=temp;
            ++cnt;
        }
        if(cnt==2){
            if(l>r) printf("%lld\n",min(query(l,n-1),query(0,r)));
            else    printf("%lld\n",query(l,r));
        }
        else{
            if(l>r) update(l,n-1,v),update(0,r,v);
            else    update(l,r,v);
        }
    }

    return 0;
}
