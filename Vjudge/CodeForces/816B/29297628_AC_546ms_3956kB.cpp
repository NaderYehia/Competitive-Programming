#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=2e6+7,OO=0x3f3f3f3f;

int freq[N];
int seg[4*N];
int n,k,q;

void build(int si=0,int ss=0,int se=N-1){
    if(ss==se){
        seg[si]=(freq[ss]>=k);
        return;
    }
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=seg[lf]+seg[rt];
}

int query(int qs,int qe,int si=0,int ss=0,int se=N-1){
    if(ss>qe||se<qs) return 0;
    if(ss>=qs&&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,lf=si*2+1,rt=si*2+2;
    return query(qs,qe,lf,ss,md)+query(qs,qe,rt,md+1,se);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    scanf("%d%d%d",&n,&k,&q);
    for(int i=0;i<n;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        ++freq[l];
        --freq[r+1];
    }
    for(int i=1;i<N;++i)
        freq[i]+=freq[i-1];

    build();

    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }

    return 0;
}
