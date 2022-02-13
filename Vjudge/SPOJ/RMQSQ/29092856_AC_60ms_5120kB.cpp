#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;

int arr[N];
int seg[4*N];
int n;

void build(int si=0,int ss=0,int se=n-1){
    if(ss==se){
        seg[si]=arr[ss];
        return;
    }
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
    build(lf,ss,md);
    build(rt,md+1,se);
    seg[si]=min(seg[lf],seg[rt]);
}

int query(int qs,int qe,int si=0,int ss=0,int se=n-1){
    if(ss>qe||se<qs) return OO;
    if(ss>=qs&&se<=qe) return seg[si];
    int md=ss+(se-ss)/2,rt=si*2+1,lf=rt++;
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
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }

    return 0;
}
